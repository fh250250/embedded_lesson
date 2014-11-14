#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[256] = {"123    456  789"};	
	char *p = buf;
	char *ret;

	while(1){
		ret = strsep(&p, " ");
		if(ret == NULL)
			break;
		if(*ret == '\0')
			continue;
		printf("ret = %s\n", ret);
		printf("p = %s\n", p);
	}

	return 0;
}



