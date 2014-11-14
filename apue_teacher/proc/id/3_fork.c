#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//子进程为父进程副本，
//	继承父进程栈，堆，缓冲区等内容
//空间相对独立
int b = 20;
int main(void)
{
	pid_t pid;
	int a = 10;

	printf("fork before!\n");	
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		a++;
		b--;
		printf("child a = %d b = %d\n",a, b);	
	}else{
		sleep(1);
		printf("father a = %d b = %d\n",a, b);
	}

	return 0;
}






