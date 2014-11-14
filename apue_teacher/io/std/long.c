#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	FILE *fp;
	int flag;
	int size;

	fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("fopen()");
		exit(1);
	}
	//记录操作之前文件指针的位置
//	flag = ftell(fp);
	
	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

	printf("size = %d\n", size);

	//恢复操作之前文件指针的位置
//	fseek(fp, flag, SEEK_SET);

	return 0;
}
