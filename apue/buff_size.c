#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int count = 0;

	while(1){
		printf("%4d", count++);
		usleep(4000);
	}
	
	return 0;
}