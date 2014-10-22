/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 
 实现一个函数，求一个具有十个元素数组的最大值
    int max(int *p, int len);

 */

#include "apue.h"

int max(int* p, int len){
	int max = *p;

	int i;
	for(i = 1; i < len; i++){
		if(*(p+i) > max)
			max = *(p+i);
	}

	return max;
}

int main(int argc, char* argv[]){

	int arr[10] = {2,1,4,100,2,4,6,7,9,89};

	printf("Max = %d\n", max(arr, 10));

	return 0;
}
