#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>


void sig_int(int signo){
	printf("@@@\n");
}


int main(){
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	//sigfillset(&set);

	//printf("%d\n", sigismember(&set, SIGINT));

	sigprocmask(SIG_BLOCK, &set, NULL);

	signal(SIGINT, sig_int);

	for(;;){
		write(1, "x", 1);
		sleep(1);
	}

	return 0;
}
