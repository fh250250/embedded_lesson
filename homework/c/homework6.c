/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 输出9*9乘法表
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int i, j;

	for(i = 1; i < 10; i++)
		printf("%5d", i);
	printf("\n");
	for(i = 1; i < 10; i++)
		printf("-----");
	printf("\n");

	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			if(j <= i){
				printf("%5d", i * j);
			}
		}

		printf("\n");
	}

	return 0;
}
