#include <stdio.h>

int main(void)
{
	char buf[256];

//	sprintf(buf, "apue/%s", "hello world!");

	fprintf(stdout, "%s", "hello world!");

//	printf("buf = %s\n", buf);

	return 0;
}
