/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 输入一行字符，分别统计出其中的英文字母，空格，数字的个数
 */

#include "apue.h"

int main(int argc, char* argv[]){

	char str[1024];
	char* pStr = str;
	int word = 0;
	int space = 0;
	int number = 0;

	printf("Please Input a string> ");
	fgets(str, sizeof(str), stdin);

	while(*pStr != '\0'){
		
		if( (*pStr >= 'a' && *pStr <= 'z') || (*pStr >= 'A' && *pStr <= 'Z') ){
			word++;
		}else if(*pStr == ' '){
			space++;
		}else if(*pStr >= '0' && *pStr <= '9'){
			number++;
		}

		pStr++;
	}

	printf("===============================================\n");
	printf("word:   %3d\n", word);
	printf("space:  %3d\n", space);
	printf("number: %3d\n", number);

	return 0;
}
