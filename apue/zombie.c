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
		sleep(2);
		exit(0);
	}else {
		int ret = wait(NULL);
		printf("father_pid = %d\n", getpid());
		while(1){
			sleep(1);
		}
	}

	return 0;
}
