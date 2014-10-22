// n!使用非递归

#include "apue.h"

unsigned int func(unsigned int n){
	unsigned int i, sum = 1;

	for(i = 1; i <= n; i++)
		sum *= i;

	return sum;
}

int main(int argc, char const *argv[])
{
	unsigned int n;

	printf("Input n> ");
	scanf("%u", &n);

	printf("%u! = %u\n", n, func(n));
	
	return 0;
}
