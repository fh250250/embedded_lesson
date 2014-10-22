#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	size_t start, end;

	start = (size_t)sbrk(0);
	printf("Our data segment at: %lu\n", start);

	int* p = (int*)sbrk(sizeof(int));
	*p = 1234;
	printf("*p = %d\n", *p);

	end = (size_t)sbrk(0);
	printf("Our data segment at: %lu\n", end);

	printf("We use mem of data: %lu\n", end - start);

	return 0;
}

