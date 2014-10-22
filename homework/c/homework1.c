/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 一元硬币兑换成1分2分5分的不同组合，打印出组合数
 */

#include "apue.h"

#define ONE_YUAN   100
#define ONE_FEN    1
#define TWO_FEN    2
#define FIVE_FEN   5


int main(int argc, char* argv[]){

	int i;
	int j;
	int k;
	int sum;
	int count = 0;

	for(i = 0; i <= (ONE_YUAN / ONE_FEN); i++ ){
		for(j = 0; j <= (ONE_YUAN / TWO_FEN); j++){
			for(k = 0; k <= (ONE_YUAN / FIVE_FEN); k++){

				sum = i * ONE_FEN + j * TWO_FEN + k * FIVE_FEN;
				
				if(sum == ONE_YUAN){
					// printf("%d  %d  %d\n", i , j ,k);
					count++;
				}

			}
		}
	}

	printf("total plans: %d\n", count);

	return 0;

}
