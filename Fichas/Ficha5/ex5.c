#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>	/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char * argv[]){

	int fd[2][2];

	if(pipe(fd[0]) < 0){
		perror("pipe");
		return 1;
	}

	if(fork() == 0){
		close(fd[0][0]);
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][1]);
		execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
		_exit(1);
	}

	close(fd[0][1]);
	wait(NULL);

	if(pipe(fd[1]) < 0){
		perror("pipe");
		return 1;
	}

	if(fork()==0){
		
		close(fd[0][0]);
		dup2(fd[0][0],STDIN_FILENO);
		
		
		close(fd[1][1]);
		dup2(fd[1][1],STDOUT_FILENO);
		

		execlp("cut", "cut", "-f7", "-d:", NULL);
		_exit(1);
	}
	close(fd[0][0]);
	close(fd[1][1]);
	wait(NULL);

	if(pipe(fd[0])<0){
		perror("pipe");
		return 1;
	}

	if(fork() == 0){
		dup2(fd[1][0], STDIN_FILENO);
		close(fd[1][0]);

		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][1]);

		execlp("uniq", "uniq", NULL);
		_exit(1);
	}

	close(fd[1][0]);
	close(fd[0][1]);
	wait(NULL);


	if (fork() == 0) {
        dup2(fd[0][0], STDIN_FILENO);
        close(fd[0][0]);

        execlp("wc", "wc", "-l", NULL);
        perror("Erro no exec wc");
        _exit(1);
    }
    close(fd[0][0]);
    wait(NULL);

    return 0;
}













