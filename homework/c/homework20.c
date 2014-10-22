/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 对12个随意输入的数进行排序
 */

#include "apue.h"

#define NUM 12

int cmp(const void* p1, const void* p2){
	return *((int*)p1) > *((int*)p2);
}

int main(int argc, char* argv[]){

	int nums[NUM] = {0};
	
	int i;
	for(i = 0; i < NUM; i++){
		printf("Input %d> ", 1 + i);
		scanf("%d", &nums[i]);
	}

	qsort(nums, NUM, sizeof(int), cmp);

	for(i = 0; i < NUM; i++)
		printf("%5d", nums[i]);

	printf("\n");

	return 0;
}
