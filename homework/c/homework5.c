/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 1 2 3 4 个数字能组成多少个互不相同且无重复数字的三位数？ 都是多少？
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int i, j, k;
	int sum = 0;

	for(i = 1; i <= 4; i++){
		for(j = 1; j <= 4; j++){
			for(k = 1; k <= 4; k++){

				if( (i!=j) && (i!=k) && (j!=k) ){
					printf("%3d ", i*100 + j*10 + k);
					sum++;
				}

			}
		}
	}

	printf("\ntotal: %d\n", sum);

	return 0;
}
