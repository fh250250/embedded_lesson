#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;

	fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		perror("open()");
		exit(1);
	}

	ret = lseek(fd, 0, SEEK_END);
	printf("ret = %d\n", ret);

	return 0;
}

