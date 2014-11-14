#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fun_int(int signo)
{
	printf("signo = %d\n", signo);
}

int main(void)
{
	int i;
	sigset_t set,oset;
	sigemptyset(&set);	
	sigemptyset(&oset);	
	sigaddset(&set, SIGINT);
	signal(SIGINT , fun_int);


	while(1){
		sigprocmask(SIG_BLOCK, &set, &oset);	
		for(i = 0; i < 5; i++){
			write(1, "x", 1);
			sleep(1);
		}
		putchar('\n');
		sigprocmask(SIG_SETMASK, &oset, NULL);	
	}

	while(1){
		sleep(1);
	}
	return 0;
}


