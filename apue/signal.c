#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void (*sighandler_t)(int);


void fun(int signo){
	printf("SIG = %d\n", signo);
	
	exit(1);
}


int main(){

	sighandler_t ret;

	ret = signal(SIGFPE, fun);
	if(ret == SIG_ERR){
		perror("signal");
		exit(1);
	}

	int a = 0;
	int b = 3 / a;

	puts("God");


	return 0;
}

