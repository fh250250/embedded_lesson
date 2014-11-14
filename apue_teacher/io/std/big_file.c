#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024LL*1024*1024*5

int main(int argc , char *argv[])
{
	FILE *fp;

	fp = fopen(argv[1], "w");
	if(fp == NULL){
		perror("fopen()");
		exit(1);
	}
//	printf("sizeof(long long) = %d\n",sizeof(long long));	

	fseek(fp, SIZE, SEEK_SET);

	fputc('a', fp);

	return 0;
}
