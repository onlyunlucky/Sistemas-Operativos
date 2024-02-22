#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


int main(int argc, char * argv[]){
	
	pid_t pid;
	char buf[10];
	int status;
	int fd[2];
	if(pipe(fd) < 0){
		perror("pipe");
		exit(1);
	}

	if(fork()==0){
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execlp("wc","wc", NULL);
		_exit(1);
	} else {
		close(fd[0]);
		int bytes;
		while(bytes=read(0,buf,10) > 0){
			write(fd[1], buf,bytes);
		}

		close(fd[1]);
		wait(NULL);
	}

	return 0;
}



