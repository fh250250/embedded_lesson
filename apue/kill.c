#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void sig_usr(int signo){
	printf("-_-\n");
}


int main(){

	pid_t pid;
	signal(SIGUSR1, sig_usr);

	if((pid = fork()) < 0){
		exit(1);
	}else if(pid == 0){
		sleep(3);
		exit(0);
	}else {
		kill(pid, SIGUSR1);
	}


	return 0;
}
