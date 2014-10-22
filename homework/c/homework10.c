/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 数组的输入和输出
    从键盘输入10个元素的整形数组，要求每个元素的取值范围是0到99,
	然后输出最大值和最小值
 */

#include "apue.h"

#define NUM 10

static int cmp(const void* p1 , const void* p2){
	return *((int*)p1) > *((int*)p2);
}

int main(int argc, char* argv[]){

	int arr[NUM] = {0};
	
	int i;
	int ret;
	for(i = 0; i < NUM;){
		printf("Input %d> ", 1 + i);
		ret = scanf("%d", &arr[i]);

		if(ret < 1){
			printf("非法输入\n");
			return 1;
		}

		if(arr[i] < 0 || arr[i] > 99){
			printf("范围: 0~99\n");
			continue;
		}

		i++;
	}

	qsort(arr, NUM, sizeof(int), cmp);

	for(i = 0; i < NUM; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Max: %d\n", arr[NUM-1]);
	printf("Min: %d\n", arr[0]);

	return 0;
}
