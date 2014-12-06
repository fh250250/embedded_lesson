#include <stdio.h>

int main(){

	int a;

	__asm__ (
		"mrs r0, cpsr\n\t"
		"and r0, r0, #0xf\n\t"
		
		"mov %0, r0\n\t"
		
		:"=r"(a)
		:
		:"r0", "memory"
	);

	switch(a){
		case 0:
			printf("User\n"); break;
		case 1:
			printf("FIQ\n"); break;
		case 2:
			printf("IRQ\n"); break;
		case 3:
			printf("Supervisor\n"); break;
		case 6:
			printf("Monitor\n"); break;
		case 7:
			printf("Abort\n"); break;
		case 10:
			printf("Hyp\n"); break;
		case 11:
			printf("Undefined\n"); break;
		case 15:
			printf("System\n"); break;
	}

	return 0;
}

