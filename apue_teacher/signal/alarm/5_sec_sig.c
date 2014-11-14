#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void fun_alrm(int signo)
{
	printf("count = %d\n", count);
}
int main(void)
{

	signal(SIGALRM, fun_alrm);

	alarm(5);

	while(1){
		count++;
	}



	return 0;
}


