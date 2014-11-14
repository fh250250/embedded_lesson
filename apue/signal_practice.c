#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void (*sighandler_t)(int);


void fun(int signo){
	printf("hello world!\n");
}


int main(){

	sighandler_t ret;

	ret = signal(SIGINT, fun);
	if(ret == SIG_ERR){
		perror("signal");
		exit(1);
	}

	int i;
	for(i = 0; ;i++){
		if(i%5 == 0)
			printf("\n");

		printf(".");
		fflush(stdout);
		sleep(1);
	}


	return 0;
}

