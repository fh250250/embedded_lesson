#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int is_prim(int num);

int main(){

	pid_t pid;

	int i;
	for(i = 0; i < 200; i++){
		pid = fork();

		if(pid < 0){
			perror("fork");
			exit(1);
		}

		if(pid == 0){
			if(is_prim(20000 + i))
				printf("pid:%d --> %d\n", getpid(), 20000 + i);

			exit(0);
		}else {
			wait(NULL);
		}
	}


	return 0;
}

int is_prim(int num){
	int i;
	for(i = 2; i <= (int)sqrt((double)num); i++){
		if(num % i == 0)
			return 0;
	}
	return 1;
}


