#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
	sigset_t set;

	sigemptyset(&set);
	//sigaddset(&set, SIGINT);
//	sigfillset(&set);
	//信号在信号集set中返回1
	//						 不在返回0
	printf("SIGINT = %d\n", sigismember( &set, SIGINT));
	printf("SIGALRM = %d\n", sigismember( &set, SIGALRM));
	printf("SIGSTOP = %d\n", sigismember( &set, SIGSTOP));


	return 0;
}


