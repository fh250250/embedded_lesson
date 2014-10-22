/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
     输入十个数，将他们存入数组a中，在输入一个数x，如果在数组中找到x，
     则输出相应的下标（若多个元素与x相同，则输出下标最小的那个元素的
	 下标）否则输出 sorry I can't find it


 */

#include "apue.h"

#define NUM 10

int main(int argc, char* argv[]){

	int a[NUM] = {0};
	int x;

	int i;
	for(i = 0; i < NUM; i++){
		printf("Input NO.%d> ", i + 1);
		scanf("%d", a+i);
	}

	printf("Input x> ");
	scanf("%d", &x);

	for(i = 0; i < NUM; i++){
		if(a[i] == x){
			printf("下标 %d\n", i);
			return 0;
		}
	}

	printf("sorry, I can't find it.\n");

	return 0;
}
