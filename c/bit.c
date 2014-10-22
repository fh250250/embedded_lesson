#include "apue.h"

struct uf {
	int num:6;			// 位域  位段
	unsigned num_1:7;
	int :12;			// 无名位域
	int :0;				// 从下一个存储单元开始
	int num_2:3;
};

int main(int argc, char const *argv[])
{
	
	// int num = -20;
	// printf("%d\n", num>>2);

	// printf("%u\n", ~0);
	// printf("%d\n", 5&6);	// 0101 & 0110 = 0100

	printf("%lu\n", sizeof(struct uf));

	return 0;
}