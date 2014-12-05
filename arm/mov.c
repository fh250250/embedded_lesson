#include <stdio.h>

int main(){

	int a;

	__asm__ (
		"mov %0, #1000\n\t"
		"ldr %0, =12345678\n\t"
		:"=r"(a)
		:
		:"memory"
	);

	printf("a = %d\n", a);

	return 0;
}

