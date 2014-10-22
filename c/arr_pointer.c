/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
 */

#include "apue.h"

void fun(int(*arr)[5], int size){
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < 5; j++)
			arr[i][j] = i * j;
}

int main(int argc, char* argv[]){

	int arr[4][5];
	fun(arr, 4);

	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++)
			printf("%5d", arr[i][j]);
		printf("\n");
	}

	return 0;
}
