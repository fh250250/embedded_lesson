#include <stdio.h>


int g;
int gi = 3;


int main(){

	static int a;
	static int ai = 3;

	printf("&a = %p\n", &a);
	printf("&g = %p\n", &g);
	printf("&ai = %p\n", &ai);
	printf("&gi = %p\n", &gi);

	return 0;
}
