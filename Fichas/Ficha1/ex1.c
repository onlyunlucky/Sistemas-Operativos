#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */


int main (int argc, char * argv[]){

int ofd,dfd,n=0; char c[1024];

// abrir o ficheiro de origem

ofd = open(argv[1],O_RDONLY);

if (ofd < 0){

	perror ("open");

	return 1;
}

// abrir ficheiro de destino

dfd=open(argv[2],O_CREAT|O_TRUNC|O_WRONLY,0666);

	if (dfd < 0){

		perror ("open");

		return 1;
	}

	// ler conteudo ficheiro origem



	while (n=read (ofd,c,sizeof[c])>0){

		// escrever no ficheiro

		write (dfd,&c,n);

		// fechar acessos

		
	}
	close (ofd);
	close (dfd);
	return 0;	
