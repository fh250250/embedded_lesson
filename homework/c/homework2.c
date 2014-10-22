/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 读入两个整数(data1, data2)和一个运算符(op)计算表达式
  data1 op data2 输出结果
 */

#include "apue.h"

int main(int argc, char* argv[]){

	int data1, data2;
	char op;
	int result;

	printf("Please Input data1: ");
	scanf("%d", &data1);

	printf("and data2: ");
	scanf("%d", &data2);

	// 清除键盘缓冲的换行符
	getchar();

	printf("and the op: ");
	scanf("%c", &op);

	switch(op){
		case '+':
			result = data1 + data2; break;
		case '-':
			result = data1 - data2; break;
		case '*':
			result = data1 * data2; break;
		case '/':
			result = data1 / data2; break;
		default:
			printf("Invalid operator.\n");
			exit(1);
	}

	printf("result = %d\n", result);

	return 0;
}
