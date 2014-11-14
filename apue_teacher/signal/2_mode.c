#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

void fun_int(int signo)
{
	printf("SIGINT = %d\n", signo);
}

int main(void)
{
	sighandler_t ret;

	//ret = signal(SIGINT, fun_int);//捕捉
	//ret = signal(SIGINT, SIG_DFL);//默认
	ret = signal(SIGINT, SIG_IGN);//忽略
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}

	while(1){
		printf("do nothing!\n");
		sleep(1);
	}


	return 0;
}


