#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(int argc, char * argv[]){

        int pid;
	int nproc = 10;
	int status;
	
	// criar todos os processos.
	for(int i = 1; i <= nproc; i++){

		if((pid = fork()) == 0){

			printf("filho: filho %d pid: %d\n",i, getpid());
			 _exit(i);
		 }
	}

	// esperar por todos os processos.
	
	for(int j = 1; j <= nproc; j++){
		int terminated_pid = wait(&status);
		printf("main: child %d pid %d\n", WEXITSTATUS(status), terminated_pid);
	}
	return 0;
}
