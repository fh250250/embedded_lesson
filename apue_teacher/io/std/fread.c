#include <stdio.h>

int main(void)
{
	int ret;
	char buf[256];	
	FILE *fp;

	fp = fopen("a","r");

	ret = fread(buf, 1, sizeof(buf), fp);

	printf("ret = %d\n",ret);

	return 0;
}


