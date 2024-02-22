#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char * argv[]){
	
	// 1. abrir ficheiro /etc/passwd
	int ifd = open ("/etc/passwd", O_RDONLY);
	// 2. abrir ficheiro saida.txt
	int ofd = open ("saida.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	// 3.abri ficheiro erros.txt
	int efd = open ("erros.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	

	// 1. stdin -> /etc/passwd
	dup2(ifd, 0);
	close(ifd);
	// 2. stdout -> saida.txt
	dup2(ofd,1);
	close(ofd);
	// 3. stderr -> erros.txt
	dup2(efd,2);
	close(efd);

	
	
	execlp("wc", "wc", NULL);
	_exit(1);
	
	wait(NULL);

	return 0;
}



