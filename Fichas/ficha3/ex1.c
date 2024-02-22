#include <unistd.h>
#include <stdio.h>

int main( int argc, char * argv[]){

	execl("/bin/ls", "ls", "-l", NULL);
	perror("exec");
	
	printf("Exec");

	return 0;

}

