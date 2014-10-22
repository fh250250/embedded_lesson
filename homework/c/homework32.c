/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-22
 * Function: 
     任意输入一个5阶方阵，输出这个方阵上三角元素里的最小值和下三角的
     最大值
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int a[5][5] = {0};

	int i, j;

	for(i = 0; i < 5; i++){
		printf("输入第%d行: ", i+1);
		scanf("%d %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	}

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	int min = a[0][0], max = a[0][0];
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(i <= j){		// 上三角
				if(a[i][j] < min)
					min = a[i][j];
			}

			if(i >= j){		// 下三角
				if(a[i][j] > max)
					max = a[i][j];
			}
		}
	}

	printf("Max=%d, Min=%d\n", max, min);

	return 0;
}

