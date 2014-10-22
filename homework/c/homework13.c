/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function:  
    有一对兔子，从出生后的第三个月开始每个月都生一对小兔子，小兔子长到
    第三个月后每个月又生一对小兔子，假如兔子不死，求每个月兔子的个数是
	多少？
 */

#include "apue.h"


int main(int argc, char* argv[]){

	// 待产 再过1个月 再过2个月
	int after[3] = {0, 0, 1};
	int months;
	int total = 1;

	printf("How much months whould U like to see: ");
	scanf("%d", &months);

	int i;
	int tmp;
	for(i = 1; i <= months; i++){
		tmp = after[0];
		after[0] += after[1];
		after[1] = after[2];
		after[2] = tmp;
		total += tmp;

		printf("第%3d个月后有 %5d 只\n", i, total * 2);
	}

	return 0;
}


