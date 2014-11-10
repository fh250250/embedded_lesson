#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

	pid_t pid;

	pid = fork();

	if(pid < 0){
		perror("fork");
		exit(1);
	}else if(pid == 0){
		printf("child_pid = %d\n", getpid());
		int a = 100/0;
		exit(0);
	}else {
		sleep(1);
		int status;
		int ret = wait(&status);
		printf("wait_ret = %d\n", ret);

		if(WIFEXITED(status))
			printf("normally!\n");
		else
			printf("exit not normally\n");

		printf("father_pid = %d\n", getpid());
		sleep(5);
	}

	return 0;
}
