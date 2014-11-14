#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int );

void fun_int(int signo)
{
	printf("hello world!\n");
}

int main(void)
{
	int i;

	sighandler_t ret;

	ret = signal(SIGINT , fun_int);
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}

	while(1){
		for(i = 0; i < 5; i++){
#if 1
			printf(".");
			fflush(stdout);
#else
			write(1, ".", 1);
#endif
			sleep(1);
		}
		putchar('\n');
	}			

	return 0;
}



