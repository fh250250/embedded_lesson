#include <stdio.h>

extern char** environ;
/*
static
*/
int main(int a, char *b[], char *envp[])
{
	int i;

	printf("a = %d\n", a);

	printf("b[0] = %s\n",b[0]);

/*
	for(i = 0; envp[i] != NULL; i++)	
		printf("%s\n",envp[i]);
*/
	return 0;
}


