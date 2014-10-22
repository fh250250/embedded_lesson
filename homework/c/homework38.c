/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 
    实现 <string.h> 中的函数
    strcpy	strcat	strcmp	strlen
 */

#include "apue.h"

char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
size_t my_strlen(const char* s);
int my_strcmp(const char* s1, const char* s2);

int main(int argc, char* argv[]){


	return 0;
}


char* my_strcpy(char* dest, const char* src){
	size_t i;
	for(i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return dest;
}

char* my_strcat(char* dest, const char* src){
	size_t dest_len = my_strlen(dest);
	size_t i;

	for(i = 0; src[i] != '\0'; i++){
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return dest;
}

size_t my_strlen(const char* s){
	size_t len;
	for(len = 0; s[len] != '\0'; len++);

	return len;
}

int my_strcmp(const char* s1, const char* s2){
	size_t s1_len = my_strlen(s1);
	size_t s2_len = my_strlen(s2);

	size_t small_len = (s1_len < s2_len ? s1_len : s2_len);

	size_t i;

	for(i = 0; i <= small_len; i++){
		if(s1[i]-s2[i] != 0){
			return (int)(s1[i]-s2[i]);
		}
	}

	return 0;
}
