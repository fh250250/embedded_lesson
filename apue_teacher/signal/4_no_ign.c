#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void(*sighandler_t)(int);

void fun_kill(int signo)
{
	printf("SIGKILL = %d\n", signo);
	
}
int main(void)
{
	sighandler_t ret;

//	signal(SIGKILL, fun_kill);
	ret = signal(SIGSTOP, SIG_IGN);
	if(ret == SIG_ERR){
		perror("signo");
		exit(1);
	}
	printf("pid = %d\n", getpid());	

	while(1){
		printf("do nothing\n");
		sleep(1);
	}


	return 0;
}


