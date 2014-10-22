#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int a = 1;

	char* p = (char*)&a;

	printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));

	return 0;
}
