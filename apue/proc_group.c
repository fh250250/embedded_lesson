#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(){

	pid_t pid;

	printf("Father pid = %d, ppid = %d, gid = %d\n", getpid(), getppid(), getpgrp());

	pid = fork();

	if(pid < 0){
		perror("fork");
		exit(1);
	}

	if(pid == 0){
		printf("Child pid = %d, ppid = %d, gid = %d\n", getpid(), getppid(), getpgrp());

		setpgrp();

		printf("Child pid = %d, ppid = %d, gid = %d\n", getpid(), getppid(), getpgrp());

		exit(0);
	}else{
		wait(NULL);
	}



	return 0;
}
