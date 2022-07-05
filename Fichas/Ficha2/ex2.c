#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(int argc, char * argv[]){

	// criar processo filho.
	int pid;
	if ((pid = fork()) == 0){

	// - Se filho:
	
	// -- imprime pid do processo
	printf("filho pid: %d\n", getpid());

	// -- imprime pid do processo pai
	printf("filho parent pid: %d\n", getppid());

	// -- sai com codigo de saida
	_exit(5);

	} else {

	// - Se pai:
	// -- imprime pid do processo
	printf("pai pid: %d\n", getpid());

	// --imprime pid do processo pai
	printf("pai parent pid: %d\n", getppid());

	// imprimir pid do processo filho
	printf("pai child pid: %d\n", pid);

	// -- aguardar que filho termine (recolhe dados do processo filho)
	int status;
	int terminated_pid = wait(&status);

	// -- imprime codigo de saida do processo filho
	printf("child process: %d, exit code %d\n",terminated_pid,  WEXITSTATUS(status));
	}

	return 0;
}
