#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#define BUFFER_SIZE 10

// vai servir como buffer interno

char buf_interno[BUFFER_SIZE];

int next_position = 0;

int last_read_bytes = 0;



int readch(int fd, char * buf){

	// se nao houver mais bytes para ler.
	
	if (next_position == last_read_bytes){

		// chegamos ao (EOF) no buffer

		int bytes = 0;

		if ((bytes = read(fd,buf_interno,BUFFER_SIZE)) < 1){

			return 1;
		}

		next_position = 0;
		last_read_bytes = bytes;
	}

	// aqui é feita a atualizaçao para saber onde está

	*buf=buf_interno[next_position];
	next_position++;

	return 0;
}



ssize_t readln(int fd, char * line,size_t size){

	int next_pos= 0;
	int read_bytes = 0;

	// ler byte a byte do fd para line

	while(next_pos < size && readch(fd,line + next_pos) == 0){

		read_bytes++;


		// condicao de paragem - quando encontrar um \n

		if(line[next_pos] == '\n'){

			break;
		}

		next_pos++;

	}

	// retornar o numero de bytes lidos.

	return read_bytes;
}




