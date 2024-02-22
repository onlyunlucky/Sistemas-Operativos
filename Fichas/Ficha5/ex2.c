#include <unistd.h>
#include <string.h>

#define MAXBUFFER 1024

int main(int argc, char * argv[]){
	
	int fd[2];
	pid_t pid;
	pipe(fd);
	char buf[MAXBUFFER];
	int status;

	if(pipe(fd) < 0){
		perror("pipe");
		exit(1);
	}

	if(fork() == 0){
		close(fd[1]);

		int bytes = 0;

		while((bytes = read(fd[0], buf, MAXBUFFER)) > 0){
			write(1, buf, bytes);
		}
		close(fd[0]);
		_exit(0);
		
	} else{

		close(fd[0]);
		close(fd[1]);
		pid = wait(&status);

		printf("[process %d] Exit status: %d\n", pid, WEXITSTATUS(status));
		printf("[process %d] Done\n", getpid());
	}

	return 0;
}
