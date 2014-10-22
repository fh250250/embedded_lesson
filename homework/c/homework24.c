/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 将一个数组逆序输出
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int origin_arr[10] = {1,2,3,4,5,6,7,8,9,10};

	int i;

	printf("origin array: ");
	for(i = 0; i < 10; i++)
		printf("%d ", origin_arr[i]);
	printf("\n");

	for(i = 0; i < 10; i++){
		printf("%d ", origin_arr[9-i]);
	}

	printf("\n");

	return 0;
}
