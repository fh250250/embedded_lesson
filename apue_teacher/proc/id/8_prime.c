#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define START 20000
#define END 20200

int main(void)
{
	int i;
	int j;
	pid_t pid;

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
		wait(NULL);
	}

	return 0;
}





