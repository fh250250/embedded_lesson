#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* src;
	FILE* dest = stdout;
	char buff[1024] = {0};
	size_t ret;


	if(argc == 1){
		src = stdin;
	}else {
		src = fopen(argv[1], "r");
		if(src == NULL){
			perror("fopen()");
			exit(1);
		}
	}


	while( ret = fread(buff, 1, sizeof(buff), src) ){
		fwrite(buff, 1, ret, dest);

		if(ret < sizeof(buff))
			break;
	}

	fclose(src);
	fclose(dest);
	
	return 0;
}
