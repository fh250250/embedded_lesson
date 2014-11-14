#include <stdio.h>


int main(int argc, char *argv[1])
{
//	printf("argc = %d\n",argc);

	int i;
	
	for(i = 0; i < argc; i++){
		printf("argc[%d] = %s\n",i,argv[i]);
	}


	return 0;
}
