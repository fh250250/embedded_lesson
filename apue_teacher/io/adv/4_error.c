#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	int fd;
	char *ret;
	
	fd = open("file", O_WRONLY);
	if(fd < 0){
#if 0
		perror("open()");
#else 
		ret = strerror(errno);		
		printf("open(): %s\n",ret);
#endif
		exit(1);
	}

//	strerror
	return 0;
}


