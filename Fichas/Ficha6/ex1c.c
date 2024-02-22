#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>	/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
	char buf;

	int fifo = open("fifo", O_RDONLY);

	while(read(fifo, &buf,1)){
		wite(1,&buf,1);
	}

	return 0;
}