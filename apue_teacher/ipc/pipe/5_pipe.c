//4.读端彻底关闭，向管道中写数据
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void fun(int signo)
{
	printf("SIGPIPE = %d\n", signo);
}
int main(void)
{
	int ret;
	int pfd[2];	
	pid_t pid;
	char buf[256];

	signal(SIGPIPE,fun);


	//pfd[0]---> 管道读端
	//pfd[1]---> 管道写端
	ret = pipe(pfd);
	if(ret < 0){
		perror("pipe()");
		exit(1);
	}
	
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		//子--> 父	
		sleep(1);	
		close(pfd[0]);
		
		printf("write before!\n");
		write(pfd[1], "hello world!\n",14);
		printf("write after!\n");

		close(pfd[1]);

	}else{
		close(pfd[1]);		
		close(pfd[0]);
	}
	wait(NULL);

	return 0;
}






