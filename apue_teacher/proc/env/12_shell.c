#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i= 0;
	char *p;
	char *ret;
	char *arg[10];
	char buf[256];
	p = fgets(buf, sizeof(buf), stdin);
	//ls -l\n\0
	//arg[0] ls
	//arg[1] -l\n
	
	buf[strlen(buf)-1] = '\0';
	while(1){
		ret = strsep( &p, " ");
		if(ret == NULL){
			break;
		}
		if(*ret == '\0'){
			continue;
		}
		printf("%s\n", ret);
		arg[i++] = ret;
	}
	arg[i] = NULL;

	if(execvp(arg[0], arg) == -1){
		perror("execvp()");
		exit(1);
	}


	return 0;
}


