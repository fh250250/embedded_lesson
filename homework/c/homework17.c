/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 2   3   5   8   13   21 
 *          --- --- --- --- ---- ----
 *           1   2   3   5   8    13
 * 求这个数列的前20项和
 */

#include "apue.h"

int main(int argc, char* argv[]){

	double sum = 0;

	double up = 2;
	double dowm = 1;
	double tmp;

	int i;
	for(i = 1; i <= 20; i++){
		sum += up/dowm;

		tmp = up;
		up = tmp + dowm;
		dowm = tmp;
	}

	printf("sum = %f\n", sum);

	return 0;
}
