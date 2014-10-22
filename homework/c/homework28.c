/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-22
 * Function: 将字符串中所有的'c'删除
 */

#include "apue.h"

int main(int argc, char* argv[]){

	char str[100] = "cabcdcfac";

	printf("原字符串: %s\n", str);

	int index;
	int i;
	for(index = 0; str[index] != '\0'; index++){
		if(str[index] == 'c'){

			// Shift
			i = index;
			while(str[i] != '\0'){
				str[i] = str[i+1];
				i++;
			}
		}
	}

	printf("删除后: %s\n", str);

	return 0;
}
