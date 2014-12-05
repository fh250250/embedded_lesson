#include <stdio.h>

int main(){

	int a = 3;
	int b = 2;
	int c = 0;

	__asm__ (
		"mov r0, %1\n\t"
		"mov r1, %2\n\t"
		"cmp r0, r1\n\t"
		"movge %0, r0\n\t"
		"movlt %0, r1\n\t"
		:"=r"(c)
		:"r"(a), "r"(b)
		:"r0", "r1", "memory"
	);

	printf("c = %d\n", c);

	return 0;
}

