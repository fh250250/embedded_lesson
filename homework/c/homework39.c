/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 
    使用递归方法实现atoi函数
    功能：将字符串转换成整数
 */

#include "apue.h"

int my_atoi(const char* p);
size_t my_atoi_r(const char* p, size_t num);
size_t tens(size_t num);

int main(int argc, char* argv[]){

	printf("%d\n", my_atoi("-1234"));

	return 0;
}

int my_atoi(const char* p){

	if(*p == '-')
		return -my_atoi_r(p+1, strlen(p) - 2);
	else
		return my_atoi_r(p, strlen(p) - 1);
}

size_t my_atoi_r(const char* p, size_t num){
	if(num == 0){
		return (*p - '0');
	}else {
		return (*p - '0')*tens(num) + my_atoi_r(p+1, num - 1);
	}
}

size_t tens(size_t num){
	size_t sum = 1;
	for(;num > 0; num--)
		sum *= 10;

	return sum;
}

