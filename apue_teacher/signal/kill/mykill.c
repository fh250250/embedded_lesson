#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[256];
	char *r, *p;

	fp = popen("ps -eo comm,pid", "r");
	if(fp == NULL){
		perror("popen()");
		exit(1);
	}

	while(1){
		p = fgets(buf, sizeof(buf), fp);
		if(p == NULL)
			break;
		while(1){
			r = strsep(&p, " ");
			if(r == NULL)	
				break;
			if(*r == '\0')
				continue;
			if(strcmp(argv[1],r) == 0){
				break;
			}
		}
		while(1){
			r = strsep(&p, " ");
			if(r == NULL)
				break;
			if(*r == '\0')
				continue;
			printf("pid = %s", r);
			//atoi
			kill(atoi(r), SIGINT);
		}
	}	

	return 0;
}





