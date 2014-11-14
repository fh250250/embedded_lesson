#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH

int main(void)
{
	int fd;
	
	umask(0);

	fd = creat("file", RWRWRW);	
	if(fd < 0){
		perror("creat");
		exit(1);
	}
	
	umask(S_IWUSR|S_IWGRP|S_IWOTH);

	fd = creat("file1", RWRWRW);	
	if(fd < 0){
		perror("creat");
		exit(1);
	}

	return 0;
}

