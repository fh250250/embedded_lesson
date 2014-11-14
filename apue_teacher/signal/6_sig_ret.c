//当同一个信号在同一个进程中被注册多次时，最后一次生效
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);
sighandler_t ret;

void fun_int1(int signo)
{
	ret = signal(SIGINT , ret);
	printf("fun_int1 : ret = %p\n", ret);
}

void fun_int2(int signo)
{
	ret = signal(SIGINT , ret);
	printf("fun_int2 : ret = %p\n", ret);
}

int main(void)
{
	ret = signal(SIGINT, fun_int1);
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}
	printf("ret = %p\n", ret);
	ret = signal(SIGINT, fun_int2);
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}
	printf("ret = %p\n", ret);
	printf("fun_int1 = %p, fun_int2 = %p\n",
						fun_int1, fun_int2);


	while(1){
		sleep(1);
	}



	return 0;
}

