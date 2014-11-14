#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);

	int i;

	for(i = 0; argv[i] != NULL; i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	return 0;
}

