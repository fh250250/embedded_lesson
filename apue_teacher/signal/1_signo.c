//信号是用正整数标识
#include <stdio.h>
#include <signal.h>

int main(void)
{
	printf("SIGHUP 	= %d\n", SIGHUP);
	printf("SIGINT 	= %d\n", SIGINT);
	printf("SIGQUIT = %d\n", SIGQUIT);
	printf("SIGILL 	= %d\n", SIGILL);
	printf("SIGALRM	= %d\n", SIGALRM);


	return 0;
}


