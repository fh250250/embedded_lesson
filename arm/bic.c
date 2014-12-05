#include <stdio.h>


// 哪一位是１哪一位就清零


int main(){

	int a = 3;
	int b = 2;
	int c = 0;

	__asm__ (
		"bic r0, %1, %2\n\t"
		"mov %0, r0\n\t"
		:"=r"(c)
		:"r"(a), "r"(b)
		:"r0", "memory"
	);

	printf("c = %d\n", c);

	return 0;
}

