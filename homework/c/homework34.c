/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 
 	找出两个字符串中的最大公共字串
    例如：
	 abccaddde dgcadde 最大公共字串 cadd
 */

#include "apue.h"

#define LEN 100
void get_sub_str(const char* src, int begin, int len, char* sub);
int have_str(const char* src, const char* sub);

int main(int argc, char* argv[]){

	char str1[LEN] = {0};
	char str2[LEN] = {0};

	printf("Input a String: ");
	scanf("%s", str1);

	printf("and Another String: ");
	scanf("%s", str2);

	// printf("%d %d\n", (int)strlen(str1), (int)strlen(str2));

	char* big;
	char* small;
	int big_len, small_len;

	if(strlen(str1) > strlen(str2)){
		big = str1;
		small = str2;
		big_len = strlen(str1);
		small_len = strlen(str2);
	}else{
		big = str2;
		small = str1;
		big_len = strlen(str2);
		small_len = strlen(str1);
	}

	// printf("big=%s, small=%s\n", big, small);

	int i;
	int j;
	char sub_str[LEN] = {0};
	for(i = small_len; i > 0; i--){ // 子串宽度
		for(j = 0; j < small_len-i+1; j++){
			
			get_sub_str(small, j, i, sub_str);

			if(have_str(big, sub_str)){
				printf("最大公共字串: %s\n", sub_str);
				return 0;
			}

		}
	}

	return 0;
}

void get_sub_str(const char* src, int begin, int len, char* sub){
	int i, index = 0;
	for(i = begin; i < begin + len; i++, index++){
		sub[index] = src[i];
	}
	sub[index] = '\0';
}

int have_str(const char* src, const char* sub){
	int i;
	int src_len = strlen(src);
	int sub_len = strlen(sub);
	char src_tmp[LEN] = {0};

	for(i = 0; i < src_len - sub_len; i++){

		get_sub_str(src, i, sub_len, src_tmp);
		if(strcmp(src_tmp, sub) == 0){
			return 1;
		}
	}

	return 0;
}
