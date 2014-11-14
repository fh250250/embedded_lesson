#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *ret;

	ret = getenv("HOME");
	printf("HOME=%s\n",ret);

	putenv("HOME=/tmp");
	ret=getenv("HOME");
	printf("HOME=%s\n", ret);

	while(1){

		sleep(1);

	}

	return 0;
}


