// 统计0x12345678有多少位1

#include <stdio.h>

int main(){

	int count = 0;

	__asm__ (
		"ldr r0, =0x12345678\n\t"
		"mov r1, #32\n\t"
		"mov r2, #0\n\t"
		
		"loop:\n\t"
		"cmp r1, #0\n\t"
		"beq loop_end\n\t"
		
		"and r3, r0, #1\n\t"
		"cmp r3, #1\n\t"
		"addeq r2, r2, #1\n\t"
		"lsr r0, r0, #1\n\t"
		
		"sub r1, r1, #1\n\t"
		"b loop\n\t"
		"loop_end:\n\t"

		"mov %0, r2\n\t"
		:"=r"(count)
		:
		:"r0", "r1", "r2", "r3", "memory"
	);

	printf("count = %d\n", count);

	return 0;
}

