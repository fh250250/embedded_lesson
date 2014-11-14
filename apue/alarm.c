#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);


void fun_alarm(int signo){
	printf("0_0\n");
}


int main(){

	sighandler_t ret;
	ret = signal(SIGALRM, fun_alarm);
	if(ret == SIG_ERR){
		perror("signal");
		exit(1);
	}

	alarm(2);

	for(;;)
		sleep(1);


	return 0;
}
