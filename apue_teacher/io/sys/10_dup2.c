#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd, fd1;
	int ret;
	char buf[256];

	fd = open(argv[1], O_RDWR);
	if(fd < 0){
		perror("open()");
		exit(1);
	}
	fd1 = open(argv[2], O_WRONLY);
	if(fd1 < 0){
		perror("open()");
		exit(1);
	}


	dup2( fd1, 1);

	while(1){
		ret = read(fd, buf, sizeof(buf));		
		if(ret == 0)
			break;
		write(1, buf, ret);
	}

	return 0;
}

