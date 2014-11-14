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
		printf("child : pid = %d, ppid = %d\n", 
							etpid(), getppid());
	}else{
		sleep(1);
		printf("father : pid = %d, ppid = %d\n", 
							getpid(), getppid());
	}

	printf("child&father : pid = %d, ppid = %d\n", 
							getpid(), getppid());

	while(1){
		sleep(1);
	}

	return 0;
}

