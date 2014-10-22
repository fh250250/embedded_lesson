/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    输入一个数组，最大值与第一个元素交换，最小值与最后一个元素交换，
    输出整个数组


 */

#include "apue.h"

#define NUM 10

void swap(int* p1, int* p2){
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main(int argc, char* argv[]){

	int arr[NUM], i;
	for(i = 0; i < NUM; i++){
		printf("Input NO.%d > ", i+1);
		scanf("%d", &arr[i]);
	}

	for(i = 0; i < NUM; i++){
		if(arr[i] > arr[0])
			swap(&arr[i], &arr[0]);
		if(arr[i] < arr[NUM-1])
			swap(&arr[i], &arr[NUM-1]);
	}

	for(i = 0; i < NUM; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}
