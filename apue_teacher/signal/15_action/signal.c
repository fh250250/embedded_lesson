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
# if 1
	struct sigaction act, oact;
	act.sa_handler = fun_int;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT , &act, &oact);
#else
	signal(SIGINT , fun_int);
#endif
	for(i = 0; i < 5; i++){
		write(1, "x", 1);
		sleep(1);
	}

	sigaction(SIGINT , &oact, NULL);

	while(1){
		sleep(1);
	}


	return 0;
}







