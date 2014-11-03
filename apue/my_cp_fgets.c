#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* in;
	FILE* out;

	in = fopen(argv[1], "r");
	if(in == NULL){
		perror("fopen()");
		exit(1);
	}

	out = fopen(argv[2], "w");
	if(out == NULL){
		perror("fopen()");
		exit(1);
	}


	char buff[1024] = {0};

	while(fgets(buff, sizeof(buff), in)){
		fputs(buff, out);
	}


	fclose(in);
	fclose(out);
	
	return 0;
}