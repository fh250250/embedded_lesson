#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define START 20000
#define END 20200

int main(void)
{
	int i;
	int j;
	pid_t pid;
	struct sigaction act;
	
	act.sa_handler = SIG_DFL;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NOCLDWAIT;

	sigaction(SIGCHLD, &act, NULL);

	for(i = START; i < END; i++){
		pid = fork();
		if(pid == 0){
			for(j = 2; j < i; j++){
				if(i%j == 0)
					break;
			}
			if(i == j)
				printf("%d\n", i);

			exit(0);
		}
	}

	while(1)
		sleep(1);

	return 0;
}





