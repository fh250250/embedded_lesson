#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	char *p;
	char *ret;
	char *arg[10];
	char buf[256];
	pid_t pid;

	while(1){
		i = 0;
		printf("[mybash@^_^]# ");
		p = fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf)-1] = '\0';
		while(1){
			ret = strsep( &p, " ");
			if(ret == NULL)
				break;
			if(*ret == '\0')
				continue;
			arg[i++] = ret;
		}
		arg[i] = NULL;
		pid = fork();
		if(pid < 0){
			perror("fork()");
			exit(1);
		}else if(pid == 0){
			if(execvp(arg[0], arg) == -1){
				perror("execvp()");
				exit(1);
			}
			exit(0);
		}
		wait(NULL);

	}
	






	return 0;
}




