#include <stdio.h>
#include <stdlib.h>

int d = 1;

int main(void)
{
	static int e;
	int a;
	int b;
	int c;
	char *p = malloc(10);	
	char *q = malloc(10);

	printf("stack_&a = %p\n", &a);
	printf("stack_&b = %p\n", &b);
	printf("stack_&c = %p\n", &c);
	printf("heap_p   = %p\n", p);
	printf("heap_q   = %p\n", q);
	
	printf("bss_&d 	 = %p\n", &d);
	printf("bss_&e 	 = %p\n", &e);

	printf("d = %d\n", d);
	printf("e = %d\n", e);


	return 0;
}


