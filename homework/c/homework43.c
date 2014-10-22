/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-29
 * Function: 
    删除一个字符串中的所有#之间的数据（包括#）如果为奇数个#则删除最后
    一个#后的所有数据
	例如：abcd##sjj#jijigo#jsij#uplo
	删除后的结果为
		abcdsjjjsij

 */

#include "apue.h"

void del_it(char* p);
void del_between(char* p, int start, int end);

int main(int argc, char* argv[]){

	char str[] = "abcd##sjj#jijigo#jsij#uplo";

	printf("%s\n", str);
	del_it(str);
	printf("%s\n", str);

	return 0;
}

void del_it(char* p){
	int i;
	int start = -1;

	for(i = 0; p[i] != '\0'; i++){
		if(p[i] == '#'){

			if(start < 0){
				start = i;
			} else{
				del_between(p, start, i);
				i = start;
				start = -1;
			}

		}
	}

	if(start >= 0)
		p[start] = '\0';

}

void del_between(char* p, int start, int end){
	int i;

	for(i = end+1; p[i] != '\0'; i++){
		p[i-end+start-1] = p[i];
	}

	p[i-end+start-1] = '\0';
}
