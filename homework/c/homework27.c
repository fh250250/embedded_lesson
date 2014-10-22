/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-22
 * Function: 
      数组中存储一个字符串，将数组中的大写字母变成小写字母，小写变大写

 */

#include "apue.h"

int main(int argc, char* argv[]){

	char str[] = "aBc +- 345";
	char* p;

	printf("原字符串: %s\n", str);
	
	for(p = str; *p != '\0'; p++){
		if(*p >= 'a' && *p <= 'z'){
			*p -= 32;
			continue;
		}
		if(*p >= 'A' && *p <= 'Z')
			*p += 32;
	}

	printf("改变后: %s\n", str);

	return 0;
}
