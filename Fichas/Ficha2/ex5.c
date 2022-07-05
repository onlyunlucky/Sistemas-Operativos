#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char * argv[]){

	// ./ex5 <valor> ex: ./ex5 20
	int valor = atoi(argv[1]);
	int linhas = 10;
	int colunas = 1000;

	// Matriz alocada na stack.
	int matriz[linhas][colunas];


	// gerar valores aleatorios.
	
	int rand_max = 1000;
	printf("gerar numeros aleatorios de 0 até %d \n", rand_max);
	for(int i = 0; i < colunas; i++){
		for(int j = 0; j < linhas; j++){
			matriz[i][j] = rand() % rand_max;
		}
	}
	printf("Done. \n");


	// Procurar o valor na matriz de forma concorrente. (Dividir trabalho por linhas)
	for (int k = 0; k < colunas; k ++){
		if (fork()==0){

			// k = indice da linha onde vai procurar. ( copia de memoria do processo-pai)
			printf("[pid %d] coluna: %d\n", getpid(), k);


			// percorre as colunas até encontrar o valor
			for (int j = 0; j < linhas; j++){

				if(matriz[k][j] == value){
					_exit(k);
				}
			}
			_exit(255); // nao encontrei i poderia ser codigo 255
		}
	}

	// aguardar pela terminacao dos processos-filhos (#procs = # linhas)
	int status;
	for(int i = 0; i < colunas; i++){
		pid_t terminated_pid = wait(&status);


		// se o processo-filho completou a sua execucao, verifica codigo de saida
		if(WIFEXITED(status)){
			if(WEXITSTATUS(status) < 255){
				//filho encontrou.
				printf("[pai] processo %d saiu, numero encontrado na col %d\n", terminated_pid, WEXITSTATUS(status));
			} else {

				//Filho nao encontrou.
				printf("[pai] processo %d saiu, nada encontrado %d\n", terminated_pid);

			}

		} else {
			// Oops, algo correu mal...
			printf("Oops");
		}
	}
	return 0;
}
