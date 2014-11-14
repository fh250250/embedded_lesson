#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_usr(int signo)
{
	printf("SIGUSR1 = %d\n", signo);

}
int main(void)
{
	pid_t pid;

	signal(SIGUSR1, sig_usr);

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		printf("child pid = %d, ppid = %d\n",
										getpid(), getppid());	
		sleep(2);
		exit(0);
	}else{
		sleep(1);
		kill(pid, SIGUSR1);
	}
	return 0;
}




