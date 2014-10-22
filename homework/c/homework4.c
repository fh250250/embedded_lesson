/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 打印1---1000之间的水仙花数
  例如: 153 = 1 + 125 + 27
 */

#include "apue.h"

// 三次方
int triple(int num);

int main(int argc, char* argv[]){

	int i;
	int units;    // 个位
	int tens;     // 十位
	int hundreds; // 百位

	for(i = 100; i < 1000; i++){
		hundreds = i / 100;
		tens     = (i / 10) % 10;
		units    = i % 10;

		if(i == triple(hundreds) + triple(tens) + triple(units)){
			printf("%d = %d^3 + %d^3 + %d^3\n", i, hundreds, tens, units);
		}
	}

	return 0;

}

int triple(int num){
	return num * num * num;
}
