#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	DIR *d;
	struct dirent *ret;

	d = opendir(argv[1]);
	if(d == NULL){
		perror("opendir()");
		exit(1);
	}
	while(1){	
		ret = readdir(d);
		if(ret == NULL)
			break;
		if(ret->d_name[0] == '.')
			continue;
		printf("%s\n", ret->d_name);
	}

	closedir(d);
	return 0;
}




