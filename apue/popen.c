#include <stdio.h>
#include <stdlib.h>


int main(){

	FILE* fp;
	char buf[256];

	fp = popen("ls", "r");
	if(fp == NULL){
		perror("popen");
		exit(1);
	}

	while(fgets(buf, sizeof(buf), fp))
		printf("%s", buf);

	return 0;
}

