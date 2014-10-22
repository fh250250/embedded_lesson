/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    将数字变成字符串
    例如： -123 变成 "-123"


 */

#include "apue.h"

int get_digit(int num);
int tens(int num);

int main(int argc, char* argv[]){

	int num;
	printf("Input a number> ");
	scanf("%d", &num);

	int digit = get_digit(num);

	// printf("%d\n", digit);

	char str[100];
	int index = 0;

	if(num < 0){
		str[index] = '-';
		index++;
		num = -num;
	}

	int i;
	for(i = digit-1; i >= 0; i--, index++){
		str[index] = ((num/tens(i)) % 10) + '0';
	}
	str[index] = '\0';

	printf("str= %s\n", str);

	return 0;
}

int get_digit(int num){
	int i, tens;
	for(i = 1, tens = 10;; i++, tens *= 10){
		if(num/tens == 0)
			break;
	}

	return i;
}

int tens(int num){
	int sum = 1;
	int i;
	for(i = 0; i < num; i++)
		sum *= 10;

	return sum;
}
