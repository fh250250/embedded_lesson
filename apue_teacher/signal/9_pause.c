#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void fun_int(int signo)
{
	sleep(2);
	printf("hello world!\n");
}

int main(void)
{
	int i,j;
	
	signal(SIGINT, fun_int);
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			write(1, "x", 1);
			sleep(1);
		}
		putchar('\n');
		//等待信号的产生
		//当信号处理函数执行完毕后，阻塞--->运行
		pause();
	}



	return 0;
}



