#include <stdio.h>

int main(void)
{
	int count = 1;

	while(1){

		printf("%4d", count++);	
		usleep(4000);	
	
	}


	return 0;
}

