#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	int ret;
	char buf[256];

	fd = open(argv[1], O_RDONLY);	
	if(fd < 0){
		perror("open()");
		exit(1);
	}

	while(1){
		ret = read(fd, buf, sizeof(buf));
		if(ret == 0){
			break;
		}
		write(1, buf, ret);
	}


	return 0;
}



