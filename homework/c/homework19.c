/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    判断一个数是不是回文
    例如：
	    1234321就是回文


 */

#include "apue.h"

int tens(int num){
	int sum = 1;
	int i;
	for(i = 0; i < num; i++)
		sum *= 10;

	return sum;
}

int main(int argc, char* argv[]){

	int num;
	printf("Please Input a Number: ");
	scanf("%d", &num);

	int i,j;
	for(i = 1, j = 10;; i++, j *= 10){
		if(num/j == 0)
			break;
	}

	int m = i; // 位数
	
	//printf("m = %d\n", m);

	int forward = num / tens(m-m/2);
	int behand = num % tens(m/2);
	//printf("forward=%d\n", forward);
	//printf("behand =%d\n", behand);

	for(i = 0; i < m/2; i++){
		if( (num%tens(i+1))/tens(i) != (num/tens(m-i-1)%10) ){
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}

