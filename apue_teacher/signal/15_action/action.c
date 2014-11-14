//sigaction 信号处理函数执行过程中
//为默认属性时(sa_flag = 0)不能被该信号本身打断，能被其他信号打断
//如果sa_flag=SA_NODEFER，并且该信号没有加入信号屏蔽字sa_mask中，能被该信号本身打断

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void fun_int(int signo)
{
	int i;
	for(i = 0; i < 5; i++){
		printf(" i = %d\n", i);
		sleep(1);
	}	
}

void sig_alrm(int signo)
{
	printf("alrm!\n");
}
int main(void)
{
	printf("pid = %d\n", getpid());
	int i;
	struct sigaction act, oact;
	act.sa_handler = fun_int;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGALRM);
	//sigaddset(&act.sa_mask, SIGINT);
//	act.sa_flags = 0;
	act.sa_flags = SA_NODEFER;
	sigaction(SIGINT , &act, &oact);
	signal(SIGALRM , sig_alrm);
	for(i = 0; i < 5; i++){
		write(1, "x", 1);
		sleep(1);
	}
	while(1){
		sleep(1);
	}
	return 0;
}







