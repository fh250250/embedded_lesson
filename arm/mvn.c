#include <stdio.h>

int main(){

	int a;

	__asm__ (
		"mvn %0, #0\n\t"
		:"=r"(a)
		:
		:"memory"
	);

	printf("a = %d\n", a);

	return 0;
}

