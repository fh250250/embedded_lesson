/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 求 1+2!+3!+...+20!的和
 */

#include "apue.h"

unsigned long fact(int num){
	unsigned long sum = 1;
	for(; num > 0; num--)
		sum *= num;

	return sum;
}

int main(int argc, char* argv[]){

	unsigned long sum = 0;
	int num;

	for(num = 1; num <= 20; num++)
		sum += fact(num);

	printf("sum=%lu\n", sum);

	return 0;
}
