//wait 属性
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
	//	int a = 100/0;
		sleep(1);		
		exit(0);
	}else{
//		sleep(1);
		int ret;
		int status;

		ret = wait(&status);
		printf("wait_ret = %d\n", ret);
		//WIFSIGNALED
#if 0
		//正常退出返回真 
		//非正常退出返回假

		if(WIFEXITED(status)){
			printf("exit normally!\n");
		}else{
			printf("exit not normally!\n");
		}
#else
		//正常退出返回假 
		//非正常退出返回真
		if(WIFSIGNALED(status)){
			printf("exit not normally!\n");
		}else{
			printf("exit normally!\n");
		}
#endif
		printf("father_pid = %d\n", getpid());
//		while(1){
			sleep(5);
	//	}
	}


	return 0;
}

