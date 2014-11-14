#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char *ret;
	char buf[256];

	fp = popen("ls", "r");
	if(fp == NULL){
		perror("popen()");
		exit(1);
	}
	while(1){
		ret = fgets(buf, sizeof(buf), fp);
		if(ret == NULL)
				break;
		printf("%s", buf);
	}

	return 0;
}


