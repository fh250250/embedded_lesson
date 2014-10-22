/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 给出一个不多于六位的数，求它是几位数，并打印出每一位数字

 */

#include "apue.h"

int main(int argc, char* argv[]){

	int num;
	printf("> ");
	scanf("%d", &num);

	if(num / 1000000 > 0){
		printf("大于6位\n");
		return 1;
	}

	int i;
	int tens;
	for(i = 1, tens = 10;; i++, tens *= 10){
		if(num/tens == 0)
			break;
	}

	printf("%d 位数\n", i);

	int nums[6] = {0};
	
	int j;
	for(j = i; j > 0; j--){
		nums[j - 1] = num % 10;
		num /= 10;
	}

	for(j = 0; j < i; j ++)
		printf("%d ", nums[j]);

	printf("\n");

	return 0;
}

