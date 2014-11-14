#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	
	
//	close(1);
	
	fd = open(argv[1], O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd < 0){
		perror("open()");
		exit(1);
	}
	
	write(fd, "hello world!\n", 14);
	

	//printf("fd = %d\n", fd);

	return 0;
}




