//pid != pgid
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid1,pid2;

	printf("Father pid = %d, ppid = %d, gid = %d\n",
									getpid(), getppid(), getpgrp());

	pid1 = fork();
	if(pid1 < 0){
		perror("fork()");
		exit(1);
	}else if(pid1 == 0){
		printf("child_1 pid = %d, ppid = %d, gid = %d\n",
									getpid(), getppid(), getpgrp());
		setpgrp();
		
		printf("child_1 pid = %d, ppid = %d, gid = %d\n",
									getpid(), getppid(), getpgrp());
		exit(0);
	}
	

	pid2 = fork();
	if(pid2 < 0){
		perror("fork()");
		exit(1);
	}else if(pid2 == 0){
		sleep(1);
		printf("child_2 pid = %d, ppid = %d, gid = %d\n",
									getpid(), getppid(), getpgrp());
//		setpgid(pid2, pid1);		
		sleep(2);
		printf("child_2 pid= %d, ppid = %d, gid = %d\n",
									getpid(), getppid(), getpgrp());
		exit(0);
	}else {
		sleep(2);
		setpgid(pid2, pid1);
	}
	wait(NULL);
	wait(NULL);
	return 0;
}


