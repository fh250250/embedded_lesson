#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int fd;
	int ret;
	char buf[256];
	
	printf("open before!\n");
	fd = open("file", O_RDONLY);
	if(fd < 0){
		perror("open()");
	}
	printf("open after!\n");

	for(i = 0; i < 3; i++){
		ret = read(fd, buf, sizeof(buf));
		printf("ret = %d\n", ret);
		if(ret == 0)
			break;
		write(1, buf, ret);
	}

	printf("read end!\n");

	return 0;
}

