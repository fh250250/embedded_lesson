#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int i;
//i = 1 apple 1
//i = 2 apple 3
//i = 3 apple 7	


	for(i = 0; i < 10; i++){
		pid = fork();
		if(pid < 0){
			perror("fork()");
			exit(1);
		}else if(pid == 0){
			printf("pid = %d\n", getpid());
			printf("apple\n");

			exit(0);	
		}
		wait(NULL);

	}


/*
	while(1){
		sleep(1);
	}
*/
	return 0;
}


