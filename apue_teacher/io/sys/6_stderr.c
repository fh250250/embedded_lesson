#include <stdio.h>
//stderr 无缓冲
int main(void)
{
	char buf[100] = "hello world!";

	fwrite(buf, 1, sizeof(buf), stderr);

	while(1){
		sleep(1);
	}

	return 0;
}

