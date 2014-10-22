/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 随意输入三个整数，把三个数由小到大顺序打印出来
 */

#include "apue.h"

int cmp(const void* p1, const void* p2){
	return (*(int*)p1) > (*(int*)p2);
}

int main(int argc, char* argv[]){

	int arr[3] = {0};

	printf("Please Input three integer: ");

	scanf("%d %d %d", arr, arr+1, arr+2);

	qsort(arr, 3, sizeof(int), cmp);

	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	return 0;
}
