#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	printf("Father pid = %d, ppid = %d\n",
									getpid(), getppid());
//	printf("gid = %d\n\n", getpgrp());
	printf("gid = %d, sid = %d\n\n",
									 getpgid(0), getsid(0));
	
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("Child_1 pid = %d, ppid = %d\n",
									getpid(), getppid());
	//	printf("gid = %d\n", getpgrp());
		printf("gid = %d, sid = %d\n", 
							getpgid(0), getsid(0));
		exit(0);	
	}

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("Child_2 pid = %d, ppid = %d\n",
									getpid(), getppid());
	//	printf("gid = %d\n", getpgrp());
		printf("gid = %d\n", getpgid(0));
		exit(0);		
	}



	return 0;
}




