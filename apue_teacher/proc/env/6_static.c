#include <stdio.h>

static int a;

int fun(void)
{
	static int b = 1;
	
	return b++;

}

int main(void)
{
	int i;
	int b = 10;	

	for(i = 0; i < 3; i++){
		printf("%d\n",fun());
	}
//	printf("%d\n", fun());
	return 0;
}

