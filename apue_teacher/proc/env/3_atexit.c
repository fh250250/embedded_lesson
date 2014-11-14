#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fun(void)
{
	
	printf("fun is run!\n");

}

int main(void)
{

	atexit(fun);
//	fun();
	sleep(2);
	exit(0);
//	return 0;
}




