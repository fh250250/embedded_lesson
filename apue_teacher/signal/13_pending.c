#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void fun(int signo)
{
	printf("signo = %d\n", signo);
}
int main(void)
{
	int i;
	sigset_t set,tmp;
	signal(SIGINT , fun);
	signal(SIGALRM , fun);
	signal(SIGUSR1  , fun);
	sigemptyset(&set);
	sigemptyset(&tmp);
	sigaddset(&set, SIGINT);
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGUSR1);
	printf("pid = %d\n", getpid());
	sigprocmask(SIG_BLOCK, &set, NULL);
	for(i = 0; i < 10; i++){
		write(1, "x", 1);
		sleep(1);
	}
	putchar('\n');
	sigpending(&tmp);
	printf("SIGINT = %d \n", sigismember(&tmp, SIGINT));
	printf("SIGALRM = %d \n", sigismember(&tmp, SIGALRM));
	printf("SIGUSR1 = %d \n", sigismember(&tmp, SIGUSR1));
	return 0;
}



