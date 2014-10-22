/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
            使用getchar输入一个字符串到一个数组中
 */

#include "apue.h"

int main(int argc, char* argv[]){

	char str[1024];
	int i = 0;

	char ch;

	while( (ch = getchar() ) != '\n'){
		str[i] = ch;
		i++;
	}

	str[i] = '\0';

	printf("%s\n", str);

	return 0;
}
