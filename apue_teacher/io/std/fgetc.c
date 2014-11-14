#include <stdio.h>


int main(void)
{
	int ch;
	
	ch = fgetc(stdin);//getchar()
	
	fputc(ch, stdout);

	//printf("ch = %d\n", ch);

	return 0;
}
