#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void fun_alarm(int signo){
	printf("hello world!\n");
	alarm(1);
}


int main(){

	if(signal(SIGALRM, fun_alarm) == SIG_ERR){
		perror("signal");
		exit(1);
	}

	alarm(1);

	for(;;)
		sleep(1);


	return 0;
}
