#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	char buff[1024] = {0};
	char* pbuff;
	char* tok;
	int i;
	char* arg[10] = {0};
	pid_t pid;

	for(;;){
		printf("> ");
		fgets(buff, sizeof(buff), stdin);
		buff[strlen(buff) - 1] = '\0';
		pbuff = buff;

		i = 0;
		while((tok = strsep(&pbuff, " ")) != NULL){
			if(*tok){
				arg[i++] = tok;
			}
		}
		arg[i] = NULL;


		// Let's fork
		pid = fork();
		
		if(pid < 0){
			perror("fork");
			exit(1);
		}

		if(pid == 0){

			if(execvp(arg[0], arg) < 0){
				perror("execvp");
				exit(1);
			}

			exit(0);
		}else {
			wait(NULL);
		}

	}

	return 0;
}
