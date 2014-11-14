#include <stdio.h>
#include <stdlib.h>


int main(){

	int ret;

	ret = system("ls");
	printf("%d\n", ret);


	return 0;
}

