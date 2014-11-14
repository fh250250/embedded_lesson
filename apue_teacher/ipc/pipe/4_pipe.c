//3.写端彻底关闭，从管道中读数据
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	int pfd[2];	
	pid_t pid;
	char buf[256];

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
		close(pfd[0]);
		
		write(pfd[1], "hello world!\n",14);

		close(pfd[1]);

	}else{
		
		sleep(1);
		close(pfd[1]);		

		//写端彻底关闭，管道中有数据
		//将管道中数据读出
		ret = read(pfd[0], buf, sizeof(buf));
		printf("ret_1 = %d\n", ret);
		write(1, buf, ret);
	
		//写端彻底关闭，管道中没有数据
		//read返回0值
		ret = read(pfd[0], buf, sizeof(buf));
		printf("ret_2 = %d\n", ret);
		write(1, buf, ret);

	
		close(pfd[0]);
	}


	return 0;
}






