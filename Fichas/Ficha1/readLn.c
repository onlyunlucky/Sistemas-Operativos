#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */


ssize_t readln(int fd, char * line,size_t size){

	int next_pos=0;
	int read_bytes = 0;

	// ler byte a byte do fd para line

	while(next_pos < size && read(fd,line + next_pos, 1)>0){

		read_bytes++;


		// condicao de paragem - quando encontrar um \n

		if(line[next_pos] == '\n'){

			break;
		}

		next_pos++;

	}

	
	// condicao de paragem - até ao fim do ficheiro

	// retornar o numero de bytes lidos.

	return read_bytes;
}


int main (int argc, char * argv[]){
	
	char buf[10];

	int fd = open(argv[1],O_RDONLY);

	// ver se fd é < 0

	if (fd < 0){

	perror ("open");

	return 1;
}

	int line_bytes=0;

	while(line_bytes = readln(fd,buf,10)>0){

		// escrever linha para o ecra

		write(STDOUT_FILENO,buf,line_bytes);

	}
	return 0;
}
