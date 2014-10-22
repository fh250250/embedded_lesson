/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 判断101到300之间有多少个素数，并输出所有素数
   提示：
      判断素数的方法，用一个数分别除以2到sqrt（这个数），如果能整除，
      则这个数不是素数，反之是素数
 */

#include "apue.h"

int is_sushu(int num);

int main(int argc, char* argv[]){

	int i;

	for(i = 101; i <= 300; i++){
		if(is_sushu(i)){
			printf("%5d", i);
		}
	}

	printf("\n");

	return 0;
}

int is_sushu(int num){
	int i;
	for(i = 2; i <= (int)sqrt((double)num); i++){
		if(num % i == 0){
			return 0;
		}
	}

	return 1;
}
