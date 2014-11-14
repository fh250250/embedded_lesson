#include <stdio.h>
//write 无缓冲


int main(void)
{
	write(1, "a", 1);
	fputc('b',stdout);	

	write(1, "a", 1);
	fputc('b',stdout);	

	write(1, "a", 1);
	fputc('b',stdout);	
	
	sleep(1);

	return 0;
}

