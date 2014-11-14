#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_chld(int signo)
{
	int ret;
	ret = wait(NULL);
	printf("# pid = %d, ppid = %d, ret = %d #\n",
						getpid(), getppid(), ret);

}
int main(void)
{
	pid_t pid;

	signal(SIGCHLD, sig_chld);

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("child:pid = %d, ppid = %d\n",
							getpid(), getppid());
		exit(0);
	}

	while(1){
		printf("do nothing!\n");
		sleep(1);
	}

	return 0;
}


