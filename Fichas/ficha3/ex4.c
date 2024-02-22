#include <unistd.h>

int main(int  argc, char * argv[]){

	char * exec_args[] = {
		"ex3",
		"arg1",
		"arg2",
		NULL,
	};

	execv("ex3", exec_args);

	return 0;
}
