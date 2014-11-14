#include <stdio.h>

int main(void)
{
	char buf[26];
	char *ret;


	//scanf("%s", buf);
	ret = gets(buf);	

//	printf("buf = %s",buf);
//	printf("ret = %s\n",ret);	

	puts(buf);

	return 0;
}

