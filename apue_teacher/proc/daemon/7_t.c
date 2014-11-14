#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int i;
	pid_t pid;
	
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid > 0){
		exit(0);		
	}else{
#if 0
		for(i = 0; i < 4; i++){
			printf("[%d]:hello!\n", i);
			sleep(1);
		}
#else
	printf("pid = %d\n", getpid());
		while(1)
			sleep(1);

#endif
	}

	return 0;
}

