//孤儿进程

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("child_pid = %d\n", getpid());
		while(1){
			sleep(1);
		}
	}else{
		printf("father_pid = %d\n", getpid());
		exit(0);
	}


	return 0;
}

