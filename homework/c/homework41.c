/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 计算一个英文句子中最长的单词长度
 */

#include "apue.h"

int max_len(const char* p);

int main(int argc, char* argv[]){

	char the_words[] = "Is everybody going crazy?";

	printf("%s\n", the_words);
	printf("max len is: %d\n", max_len(the_words));

	return 0;
}

int max_len(const char* p){
	int max = 0;
	int count = 0;

	for(; *p != '\0'; p++){
		if(*p == ' '){
			if(count > max) max = count;
			count = 0;
		}else {
			count++;
		}
	}

	return max;
}
