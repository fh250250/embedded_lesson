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
	sigprocmask(SIG_BLOCK, &set, &oset);	
	while(1){
		for(i = 0; i < 5; i++){
			write(1, "x", 1);
			sleep(1);
		}
		putchar('\n');
#if 0
		sigprocmask(SIG_SETMASK, &oset, &set);	
		pause();
		sigprocmask(SIG_SETMASK, &set, &oset);
#else
		sigsuspend(&oset);
#endif

	}
	while(1){
		sleep(1);
	}
	return 0;
}


