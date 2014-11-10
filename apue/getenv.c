#include <stdio.h>
#include <stdlib.h>


int main(){

	printf("%s\n", getenv("PATH"));

	putenv("HOME=/tmp");
	printf("%s\n", getenv("HOME"));

	return 0;
}
