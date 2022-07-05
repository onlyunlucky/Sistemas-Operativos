#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main(int argc, char * argv[]){

	// imprimir pid do processo
	printf("pid: %d\n", getpid());

	// imprimir PID do processo pa
	printf("parent pid: %d\n",getppid());

	return 0;
}
