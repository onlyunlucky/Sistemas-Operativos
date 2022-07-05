#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */



int main (int argc, char * argv[]){
	
	char buf[10];

	int fd = open(argv[1],O_RDONLY);

	// ver se fd é < 0

	if (fd < 0){

	perror ("open");

	return 1;
}

	int line_bytes=0;

	while(line_bytes = read(fd,buf,10)>0){

		// escrever linha para o ecra

		write(STDOUT_FILENO,buf,line_bytes);

	}
	return 0;
}