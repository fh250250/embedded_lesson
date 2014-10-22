/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-23
 * Function: 
    几个人围成一圈，他们的ID号是从1到10，从第一个人开始，数到3的人将
    不再参加游戏，下一个人重新开始从1开始数数，请打印最后剩下的人的
	ID号
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int ids[10] = {1,2,3,4,5,6,7,8,9,10};

	int people = 10;
	int index = 0;
	int i;

	for(i = 0; people > 1; i++){

		if(ids[i%10] == 0){
			continue;
		}else {
			index++;
		}

		if(index == 3){
			ids[i%10] = 0;
			people--;
			index = 0;
		}
	}

	for(i = 0; i < 10; i++){
		if(ids[i] != 0)
			printf("result=%d\n", ids[i]);

	}

	return 0;
}
