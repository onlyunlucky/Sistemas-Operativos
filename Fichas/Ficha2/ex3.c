#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(int argc, char * argv[]){

        int pid;
	int nproc = 10;
	int status;

	for(int i = 1; i <= nproc; i++){

		// criar processo filho
		if((pid = fork()) == 0){

				// Se filho:
				// // - print do seu pid
				 printf("filho: filho %d pid: %d\n",i, getpid());
				 // - sai com codigo de saida igual ao numero sequencial
				 _exit(i);
		 } else {

		// Se pai(main):
		// - esperar que o processo filho termine
		int terminated_pid = wait(&status);
		// - imprime codigo de saida do processo-filho

		printf("main: filho %d pid: %d\n", WEXITSTATUS(status), terminated_pid);
		}
	}


	return 0;
}
