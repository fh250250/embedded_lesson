#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
	size_t start, end;

	start = (size_t)sbrk(0);
	printf("Our data segment at: %lu\n", start);

	int* p = malloc(sizeof(int));

	end = (size_t)sbrk(0);
	printf("Our data segment at: %lu\n", end);

	printf("We use mem of data: %lu\n", end - start);

	
	malloc_stats();

	malloc(sizeof(char) * 1024 * 200); // 200M

	malloc_stats();

	return 0;
}

