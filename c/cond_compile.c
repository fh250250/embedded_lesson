#include <stdio.h>

#define _S_

int main(int argc, char const *argv[])
{

#ifdef _S_		// #ifndef
	printf("suss\n");
#else
	printf("fail\n");
#endif

	return 0;
}