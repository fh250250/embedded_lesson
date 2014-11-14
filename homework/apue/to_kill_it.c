#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void sig_usr1(int signo){
	printf("Yeah, what's the matter?\n");
}


int main(){

	if(signal(SIGUSR1, sig_usr1) == SIG_ERR){
		perror("signal");
		exit(1);
	}

	for(;;){
		printf("I block here\n");
		sleep(1);
	}

}

