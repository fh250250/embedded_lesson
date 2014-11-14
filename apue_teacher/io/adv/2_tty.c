#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd10,fd11;
	char buf[256];

	fd10 = open("/dev/tty10", O_RDWR);
	if(fd10 < 0){
		perror("open");
		exit(1);
	}

	fd11 = open("/dev/tty11", O_RDWR);
	if(fd11 < 0){
		perror("open()");
		exit(1);
	}
	int ret;

	write(fd11, "\nTTY11:\n\n", 8);

	ret = read(fd11, buf, sizeof(buf));
	
	write(fd10, buf, ret);	

	close(fd10);
	close(fd11);

	return 0;
}

