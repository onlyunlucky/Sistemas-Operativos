#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char * argv[]){

	printf("antes do exec\n");

	if(fork()==0){
		// so a imagem do processo filho é que vai ser substituido pela do "ls -l"
		execl("/bin/ls", "ls", "-l", NULL);
		perror("exec"); // caso dê erro
		_exit(1);// caso algo corra mal com o "execl"
	}

	printf("filho criado com exec\n");

	int status;
	pid_t terminated_pid = wait(&status);

	printf("filho %d terminou \n", terminated_pid);

	return 0;


}
