/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    利用条件运算符完成下面:
    学习成绩大于等于90分同学打印A，60到89之间的用B打印，小于60分的打印C


 */

#include "apue.h"

int main(int argc, char* argv[]){

	int score;

	printf("Input Your Score: ");
	scanf("%d", &score);

	if(score < 60)
		printf("C\n");
	else if(score < 90)
		printf("B\n");
	else
		printf("A\n");

	return 0;
}

