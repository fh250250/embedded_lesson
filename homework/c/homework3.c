/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 求1---1000之间满足 用3除余2 用5除余3 用7除余1 的数
  要求: 每行打印5个数
 */

#include "apue.h"

#define CONDITION(a) ( (a%3==2) && (a%5==3) && (a%7==1) )

int main(int argc, char* argv[]){

	int i;
	int count = 0;

	for(i = 1; i <= 1000; i++){
		if(CONDITION(i)){
			printf("%d  ", i);
			count++;
			if(count%5==0)
				printf("\n");
		}

	}

	return 0;

}
