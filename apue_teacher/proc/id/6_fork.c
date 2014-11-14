//僵尸进程
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
		exit(0);
	}else{
		int ret;
		ret = wait(NULL);
		printf("wait_ret = %d\n", ret);

		printf("father_pid = %d\n", getpid());
//		while(1){
			sleep(5);
	//	}
	}


	return 0;
}

