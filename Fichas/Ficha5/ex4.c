#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

	int fd[2];
	char buf[10];
	if(pipe(fd) < 0){
		perror("pipe");
		exit(1);
	}

	if(fork()== 0){
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		execlp("ls","ls","/etc", NULL);
		_exit(1);
	}

	close(fd[1]);

	if(fork()==0){
		dup2(fd[0], 0);
		close(fd[0]);
		execlp("wc","wc","-l", NULL);
		_exit(1);
	}

	close(fd[0]);
	wait(NULL);

	return 0;
}