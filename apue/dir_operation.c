#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main(int argc, char const *argv[])
{
	DIR* d;
	struct dirent* ret;

	d = opendir(argv[1]);

	if(d == NULL){
		perror("opendir");
		exit(1);
	}

	while((ret = readdir(d)) != NULL)
		if(ret->d_name[0] != '.')
			printf("%s\n", ret->d_name);


	closedir(d);

	return 0;
}
