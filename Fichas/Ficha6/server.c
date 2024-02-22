#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h>	/* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	char buf[1];

	if(mkfifo("fifo",0666) == -1){
		perror("Erro pipe");
		return 1;
	}

	int log = open("log.txt", O_CREAT | O_WRONLY, 0666);
	if(log == -1){
		perror("Erro com ficheiro log");
		return 2;
	}

	int ler = open("fifo",O_RDONLY);


	while(read(ler,&buf,1)){
		write(log,&buf,1);
	}


	close(log);
	unlink("fifo");


	return 0;
}