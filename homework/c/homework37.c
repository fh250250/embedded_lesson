/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 从键盘上输入若干学生成绩，统计出平均成绩，并输出高于平均分的成绩
 */

#include "apue.h"

double average(double *p, int len);

int main(int argc, char* argv[]){

	double scores[100] = {0};

	int i;
	double score;
	for(i = 0;;i++){
		printf("输入第%d个学生成绩(-1结束)> ", i+1);
		scanf("%lf", &score);
		
		if(score < 0){
			break;
		}else{
			scores[i] = score;
		}
	}

	int len = i;

	double avg = average(scores, len);
	printf("平均值: %lf\n", avg);

	for(i = 0; i < len; i++){
		if(scores[i] > avg)
			printf("%lf ", scores[i]);
	}

	printf("\n");

	return 0;
}

double average(double *p, int len){
	double sum = 0;
	int i;

	for(i = 0; i < len; i++)
		sum += *(p+i);

	return sum/len;
}

