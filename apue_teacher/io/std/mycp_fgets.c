#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src, *dest;
	char buf[256];
	char *ret;

	src = fopen(argv[1], "r");
	if(src == NULL){
		perror("fopen()");
		exit(1);
	}

	dest = fopen(argv[2], "w");
	if(dest == NULL){
		perror("fopen()");
		exit(1);
	}

	while(1){
		ret = fgets(buf, sizeof(buf), src);
		if(ret == NULL)
			break;		
		fputs(buf, dest);
	}

	//size-->256
	//fgets -->
	//buf-->abcd\0\0\0\0abcd\0\0\0\n

	//fputs--->

	return 0;
}








