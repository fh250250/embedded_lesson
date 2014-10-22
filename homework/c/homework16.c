/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
    一个球从100米落下，每次落地后反弹回原来高度的一半，再落下，
    求第十次落地时，共经历了多少米？第十次反弹多高？


 */

#include "apue.h"

int main(int argc, char* argv[]){

	int i;

	double height = 100;
	double total = 0;

	for(i = 1; i <= 10; i++){
		total += height;

		if(i > 1)
			total += 2 * height;

		height /= 2;
	}

	printf("第十次落地时，共经历了 %f 米, 第十次反弹 %f 米\n", total, height/2);

	return 0;
}

