#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	pid_t pid;

	printf("Father pid = %d, ppid = %d\n", 
									getpid(), getppid());
	printf("gid = %d, sid = %d\n\n",
									getpgrp(), getsid(0));

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("child_before pid = %d, ppid = %d\n", 
									getpid(), getppid());
		printf("gid = %d, sid = %d\n",
									getpgrp(), getsid(0));
		
		if(setsid() == -1){
			perror("setsid()");
			exit(1);
		}
		
		printf("child_after pid = %d, ppid = %d\n", 
									getpid(), getppid());
		printf("gid = %d, sid = %d\n",
									getpgrp(), getsid(0));

		exit(0);
	}else{
		wait(NULL);
	}


	return 0;
}


