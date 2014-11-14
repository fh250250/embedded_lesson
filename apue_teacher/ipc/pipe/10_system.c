#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ret;

//	while(1){
		ret = system("cp t.txt ./fifo");
		sleep(1);
//	}

	return 0;
}

