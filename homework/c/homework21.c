/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 求0到7所能组成的奇数的个数
 */

#include "apue.h"

int power(int base, int num){
	int i;
	int sum = 1;
	for(i = 0; i < num; i++)
		sum *= base;

	return sum;
}

int main(int argc, char* argv[]){

	int i;
	int sum = 0;
	for(i = 1; i <= 8; i++){
		if(i == 1){
			sum += 4;
		}else if(i == 2){
			sum += 4*7;
		}else{
			sum += 4*7*power(8, i-2);
		}
	}

	printf("result=%d\n", sum);

	return 0;
}
