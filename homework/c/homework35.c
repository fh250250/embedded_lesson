/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 找出三个数中的最大值，最小值，且做差
 */

#include "apue.h"

int max(int a, int b, int c);
int min(int a, int b, int c);

int main(int argc, char* argv[]){

	int a = 10;
	int b = 3;
	int c = 5;

	printf("Max = %d\n", max(a, b, c));
	printf("Min = %d\n", min(a, b, c));
	printf("Max - Min = %d\n", max(a, b, c) - min(a,b,c));

	return 0;
}

int max(int a, int b, int c){
	int max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;

	return max;
}

int min(int a, int b, int c){
	int min = a;
	if(b < min)
		min = b;
	if(c < min)
		min = c;

	return min;
}
