#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[1];
	int ret;

	if(argc == 1){
		fp = stdin;
	}else{
		fp = fopen(argv[1], "r");	
		if(fp == NULL){
			perror("fopen()");
			exit(1);
		}
	}

	//buf[5];		
	//

	while(1){
		ret = fread(buf, 1, sizeof(buf), fp);
		if(ret == 0){
		//	perror("fread()");
		//	exit(1);
		}
		//printf("buf = %s\n", buf);

		fwrite(buf, 1, ret, stdout);
		if(ret < sizeof(buf))
			break;
	}

	return 0;
}



