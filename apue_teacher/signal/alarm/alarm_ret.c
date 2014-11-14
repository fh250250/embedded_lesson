#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

void fun_alrm(int signo)
{
	printf("SIGALRM = %d\n", signo);
}
int main(void)
{
	int a;
	sighandler_t ret;

	ret = signal(SIGALRM, fun_alrm);
	if(ret == SIG_ERR){
		perror("signal()");
		exit(1);
	}
	//每个进程只能设置一个闹钟
	//当设置多个时，后一个将替代前一个
	//返回值为上一个闹钟的剩余秒数
	a = alarm(2);
	printf("a = %d\n", a);

	a = alarm(4);
	printf("a = %d\n", a);
	
	sleep(1);
	a = alarm(3);
	printf("a = %d\n", a);

	while(1){
		printf("do nothing!\n");
		sleep(1);
	}

	return 0;
}


