/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-10-8
 * Function: 
 	两个字符串a b，将a b两个字符串中的较大者放入c中
    要求：
	  c 使用动态开辟，并分函数
 */

#include "apue.h"

char* get_max(char* a, char* b){
	char* max = NULL;

	max = strcmp(a, b) > 0 ? a : b;

	char* c = NULL;

	c = malloc((strlen(max)+1) * sizeof(char));
	if(c == NULL)
		exit(-1);

	strcpy(c, max);

	return c;
}

int main(int argc, char* argv[]){

	char a[] = "123s45";
	char b[] = "1234567";

	char* c = get_max(a, b);

	printf("%s\n", c);

	return 0;
}
