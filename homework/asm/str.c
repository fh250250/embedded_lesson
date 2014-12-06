#include <stdio.h>

int strcmp(const char* s1, const char* s2){
	int ret;

	__asm__ (
		"mov r0, %1\n\t"
		"mov r1, %2\n\t"
		
		"loop_cmp:\n\t"
		"ldrb r2, [r0], #1\n\t"
		"ldrb r3, [r1], #1\n\t"

		"cmp r2, #0\n\t"
		"beq loop_cmp_end\n\t"
		"cmp r3, #0\n\t"
		"beq loop_cmp_end\n\t"

		"cmp r2, r3\n\t"
		"beq loop_cmp\n\t"
		
		"loop_cmp_end:\n\t"
		"sub r4, r2, r3\n\t"
		"mov %0, r4\n\t"

		:"=r"(ret)
		:"r"(s1), "r"(s2)
		:"r0", "r1", "r2", "r3", "r4", "memory"
	);

	return ret;
}

char* strcpy(char* dest, const char* src){

	__asm__ (
		"mov r0, %0\n\t"
		"mov r1, %1\n\t"
		
		"loop_cpy:\n\t"
		"ldrb r2, [r1], #1\n\t"
		"strb r2, [r0], #1\n\t"
		"cmp r2, #0\n\t"
		"bne loop_cpy\n\t"

		:
		:"r"(dest), "r"(src)
		:"r0", "r1", "r2", "memory"
	);

	return dest;
}

char* strncpy(char* dest, const char* src, size_t n){

	__asm__ (
		"mov r0, %0\n\t"
		"mov r1, %1\n\t"
		"mov r3, %2\n\t"
		
		"loop_ncpy:\n\t"
		"ldrb r2, [r1], #1\n\t"
		"strb r2, [r0], #1\n\t"
		
		"sub r3, r3, #1\n\t"
		"cmp r3, #0\n\t"
		"bne loop_ncpy\n\t"

		"strb r3, [r0]\n\t"
		
		:
		:"r"(dest), "r"(src), "r"(n)
		:"r0", "r1", "r2", "r3","memory"
	);

	return dest;
}

int main(){

	char s1[10] = "3";
	char s2[10] = "1234";

	printf("ret = %d\n", strcmp(s1, s2));
	printf("s1 = %s\n", strcpy(s1, s2));
	printf("s1 = %s\n", strncpy(s1, s2, 3));

	return 0;
}

