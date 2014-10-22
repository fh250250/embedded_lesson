/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-23
 * Function: 
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int a = 1;
	int b = 2;

	// const int* p = &a;
	// p = &b;

	int* const p = &a;
	*p = 100;

	printf("*p=%d\n", *p);

	return 0;
}
