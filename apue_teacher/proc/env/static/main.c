#include <stdio.h>

extern int a;

int main(void)
{
	int ret;

	ret = add();
	printf("ret = %d\n", ret);
	printf("a = %d\n",a);


//	int a = 2;

//	int a;
	/*
	{
		int a = 1;
		printf("a = %d\n", a);
//	add();
	}
*/
//	printf("a = %d\n",a);


	return 0;
}
