#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fun_alrm(int signo)
{
	alarm(1);
	printf("hello world!\n");
}
int main(void)
{
	signal(SIGALRM, fun_alrm);
	alarm(1);
	while(1)
		sleep(1);
	return 0;
}

