#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(){

	int fd;
	umask(0);
	creat("file", RWRWRW);

	if(fd < 0){
		perror("create");
		exit(1);
	}

	return 0;
}

