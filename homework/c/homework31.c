/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-23
 * Function: 将一个输入的字符串反转
 */

#include "apue.h"

int main(int argc, char* argv[]){

	char buff[1024] = {0};

	printf("Input a String: ");
	scanf("%s", buff);

	int len = strlen(buff);

	int i;
	char tmp;
	for(i = 0; i < len/2; i++){
		tmp = buff[i];
		buff[i] = buff[len-i-1];
		buff[len-i-1] = tmp;
	}

	printf("result=%s\n", buff);

	return 0;
}
