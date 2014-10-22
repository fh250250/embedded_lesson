/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    一个已经按顺序排好的数组，现在输入一个数要求按照原来的顺序将它
    插入数组中


 */

#include "apue.h"

int main(int argc, char* argv[]){

	int sorted_arr[11] = {2,4,6,8,10,12,14,16,18,20};

	printf("原数组: ");
	int i;
	for(i = 0; i < 10; i++)
		printf("%d ", sorted_arr[i]);
	printf("\n输入一个要插入的数> ");

	int num;
	scanf("%d", &num);

	int j;
	for(i = 0; i < 10; i++){
		if(num < sorted_arr[i]){
			for(j = 9; j >= i; j--){
				sorted_arr[j+1] = sorted_arr[j];
			}

			sorted_arr[i] = num;
			break;
		}
	}

	if(i == 10)
		sorted_arr[10] = num;

	printf("插入后: ");
	for(i = 0; i < 11; i++)
		printf("%d ", sorted_arr[i]);
	printf("\n");

	return 0;
}
