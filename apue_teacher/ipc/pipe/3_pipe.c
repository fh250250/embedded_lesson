//2.首先为写操作，还没有从管道中读数据
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	int count = 0;
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

		while(1){
			printf("count = %d\n", count++);
			write(pfd[1], "hello world!\n",14);
		}
		close(pfd[1]);

	}else{
		close(pfd[1]);		
		
		sleep(3);

		while(1){
			ret = read(pfd[0], buf, sizeof(buf));
		}
		write(1, buf, ret);
		
		close(pfd[0]);
	}


	return 0;
}






