/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 判断一个素数能被几个9整除
 */

#include "apue.h"

int is_prime(int num){
	int i;
	for(i = 2; i <= (int)sqrt((double)num); i++){
		if(num % i == 0){
			return 0;
		}
	}

	return 1;
}

int main(int argc, char* argv[]){


	int num;

	printf("Input> ");
	scanf("%d", &num);

	int i;
	int count;
	int tmp;

	for(i = 2; i <= num; i++){
		if( is_prime(i) ){
			tmp = i;
			count = 0;
			while(tmp != 0){
				count++;
				tmp /= 9;
			}

			printf("%d 能被 %d 个 9 除完\n", i, count);
		}
	}

	return 0;
}

