
// isto é tipo o esboço do my_system
// este está preparado apenas para o "ls -l"


int my_system (char  * command ) {
	// 1. separar comandos por espaços. ["ls", "-l"]
	
	char * exec_args = {
		"ls",
		"-l",
		NULL,
	};

	if(fork()==0){
		execvp("ls", exec_args);
		_exit(1);
	}


	int status = 0;
	wait(&status);


	// se WIFEXITED(status), entao retorna WEXITSTATUS(status);
	// senao, retorna -1
	

	return 0;
}





int main (int argc, char * argv[]){

	char *  command = "ls -l";


	for ( int i = 0; i < 2; i++){
		my_system("ls -l");
	}

	return 0; // my_system("ls -l");
}
