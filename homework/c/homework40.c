/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 
    实现函数：
	将两位数A C合并为一个四位数B
    将两个两位数 A的个位和十位放到B的百位和个位上，
	C的个位和十位放到B的千位和十位上
	B是个四位数

 */

#include "apue.h"

int combine(int a, int c);

int main(int argc, char* argv[]){

	int a = 12;
	int c = 34;
	printf("a=%d, c=%d\n", a, c);
	printf("b=%d\n", combine(a, c));

	return 0;
}

int combine(int a, int c){
	int a1 = a%10; 		// a 的个位
	int a2 = a/10%10; 	// a 的十位
	
	int c1 = c%10;		// c 的个位
	int c2 = c/10%10;   // c 的十位

	return a1*100 + a2 + c1*1000 + c2*10;
}
