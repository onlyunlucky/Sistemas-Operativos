#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]){
	int pipe_fd[2];
	if(pipe(pipe_fd) < 0){
		perror("pipe");
		_exit(1);
	}

	// criar processo-filho
	if(fork()==0){
		// recebe descritores do pipe.
		// temos que fechar o descritor que é necessário
		close(pipe_fd[0]);
		char buf[10];
		int bytes = read(pipe_fd[1], buf, 10);
		close(pipe_fd[1]);
		write(1,buf,bytes);
		_exit(0);
	}else {
		close(pipe_fd[1]);

		char * str = "teste";
		write(pipe_fd[0],str, strlen(str));
		close(pipe_fd[0]);
		// comunicaçao pai - filho
		wait(NULL);
	}
	return 0;
}
