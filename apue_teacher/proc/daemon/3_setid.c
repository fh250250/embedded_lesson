//pid == pgid != 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	
	printf("Father pid = %d, ppid = %d,gid = %d\n",
									getpid(), getppid(), getpgrp());
	
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("Child_before pid = %d, ppid = %d,gid = %d\n",
									getpid(), getppid(), getpgrp());
		sleep(2);
	//	setpgrp();
	//	setpgid(0, 0);
		printf("Child_after pid = %d, ppid = %d,gid = %d\n",
									getpid(), getppid(), getpgrp());
		exit(0);
	}else {
		sleep(1);
		//创建一个进程组
		//组长进程为pid
		setpgid(pid , pid);
	
	}
	wait(NULL);

	return 0;
}




