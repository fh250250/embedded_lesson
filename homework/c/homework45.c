/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-10-8
 * Function: 
 从键盘输入两个字符串，将两个字符串分别排序，并删除各自重复的字符
    然后将他们合并，合并后的字符也要排序，并且删除相同的字符
	要求：
		合并后的字符数组要在函数中动态开辟空间
 */

#include "apue.h"

int cmp(const void* p1, const void* p2){
	return (*(char*)p1) > (*(char*)p2);
}

void deal_with(char* str);
char* combine(const char* s1, const char* s2);

int main(int argc, char* argv[]){

	char str1[100] = {0};
	char str2[100] = {0};

	printf("Input str1> ");
	scanf("%s", str1);
	printf("and str2> ");
	scanf("%s", str2);

	deal_with(str1);
	deal_with(str2);

	//printf("str1 = %s\n", str1);
	//printf("str2 = %s\n", str2);

	char* str = combine(str1, str2);
	printf("str = %s\n", str);

	return 0;
}

void deal_with(char* str){
	size_t i;
	size_t index;

	qsort(str, strlen(str), sizeof(char), cmp);
	//printf("> %s\n", str);
	
	for(i = 0; str[i] != '\0';){
		if(str[i] == str[i + 1]){
			
			for(index = i; str[index] != '\0'; index++){
				str[index] = str[index + 1];
			}
			continue;
		}

		i++;
	}
}

char* combine(const char* s1, const char* s2){
	char* str = NULL;

	str = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if(str == NULL){
		exit(-1);
	}

	strcpy(str, s1);
	strcat(str, s2);

	deal_with(str);

	return str;
}
