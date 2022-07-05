#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include "readLn.h"


int main (int argc, char const *argv[]){

	int fd=open(argv[1],O_RDONLY);

	char buf[1024];

	int bytes = 0;

	while((bytes = readLn(fd,buf,1024)) > 0){

		write(STDOUT_FILENO,buf,bytes);
	}

	return 0;
}