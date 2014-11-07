#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
	int ret;
	struct stat buf;

	ret = stat(argv[1], &buf);
	if(ret < 0){
		perror("stat");
		exit(1);
	}

	if(S_ISDIR(buf.st_mode))
		printf("d");
	else if(S_ISCHR(buf.st_mode))
		printf("c");
	else if(S_ISBLK(buf.st_mode))
		printf("b");
	else if(S_ISREG(buf.st_mode))
		printf("-");
	else if(S_ISFIFO(buf.st_mode))
		printf("p");
	else if(S_ISLNK(buf.st_mode))
		printf("l");
	else if(S_ISSOCK(buf.st_mode))
		printf("s");
	printf("\n");





	printf("%lu\n", buf.st_mtime);
	printf("%ld\n", buf.st_size);
	printf("%ld\n", buf.st_nlink);


	return 0;
}