#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	FILE *fp, *fp1;
	
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("fopen()");
		exit(1);
	}

	fp1= fopen(argv[2], "w");	
	if(fp1 == NULL){
		perror("fopen()");
		exit(1);
	}
	

	while(1){
		ch = fgetc(fp);	
		if(ch == EOF){
			break;
		}
		fputc(ch, fp1);
	}


	return 0;
}


