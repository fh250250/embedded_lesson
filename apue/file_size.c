#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE* fp = fopen(argv[1], "r");
	if(!fp){
		perror("fopen()");
		return 1;
	}

	fseek(fp, 0, SEEK_END);

	printf("%ld\n", ftell(fp));

	fclose(fp);
	
	return 0;
}