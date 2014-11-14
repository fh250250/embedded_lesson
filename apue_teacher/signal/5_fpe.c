#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

void fun_fpe(int signo)
{
	printf("SIGFPE = %d\n", signo);
	sleep(1);
}

int main(void)
{
	int a ;

	sighandler_t ret;
	
	ret = signal(SIGFPE, fun_fpe);
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}

	a = a/0;	

	printf("\n-------\n");

	return 0;
}


