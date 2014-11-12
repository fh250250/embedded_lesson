#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

	pid_t pid;

	printf("Father pid = %d, ppid = %d, gid = %d, sid = %d\n", getpid(), getppid(), getpgrp(), getsid(0));

	pid = fork();

	if(pid < 0){
		perror("fork");
		exit(1);
	}

	if(pid == 0){
		printf("Child pid = %d, ppid = %d, gid = %d, sid = %d\n", getpid(), getppid(), getpgrp(), getsid(0));
		if(setsid() == -1){
			perror("setsid");
			exit(1);
		}
		printf("Child pid = %d, ppid = %d, gid = %d, sid = %d\n", getpid(), getppid(), getpgrp(), getsid(0));

		exit(0);
	}else {
		wait(NULL);
	}


	return 0;
}

