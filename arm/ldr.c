#include <stdio.h>

int main(){

	int a[6] = {1,2,3,4,5,6};
	int b[6] = {0};

	__asm__ (
		"mov r0, %0\n\t"
		"mov r1, %1\n\t"
		"mov r3, #6\n\t"

		"loop:\n\t"
		
		"cmp r3, #0\n\t"
		"beq end_loop\n\t"
		
		"ldr r2, [r1], #4\n\t"
		"str r2, [r0], #4\n\t"
		
		"sub r3, r3, #1\n\t"
		"b loop\n\t"

		"end_loop:\n\t"
		
		:
		:"r"(b), "r"(a)
		:"r0", "r1", "r2", "r3", "memory"
	);

	int i;
	for(i = 0; i < 6; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}

