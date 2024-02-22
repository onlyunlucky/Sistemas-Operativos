#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main (int argc, char * argv[]){

	
	for ( int i = 1; i < argc; i++){
		printf("argv[%d]: %s\n", i, argv[i]);
		if(fork()== 0){
			execlp(argv[i], argv[i], NULL); // execlp("ls", "ls", NULL);
			_exit(1);
		}

	}

	// esperar por processo
	
	for( int i = 1; i < argc; i++){
		// waits....
		int status = 0;
		wait(&status);
		
	}

	return 0;
}
