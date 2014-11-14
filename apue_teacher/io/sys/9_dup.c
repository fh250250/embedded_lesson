#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int oldfd, newfd;

	oldfd = open(argv[1], O_RDWR|O_CREAT,0644);
	if(oldfd < 0){
		perror("open()");
		exit(1);
	}

	newfd = dup(oldfd);
	if(newfd < 0){
		perror("dup()");
		exit(1);
	}

	write(newfd, "hello", 5);
	write(oldfd, "world", 5);

	printf("oldfd = %d\n", oldfd);
	printf("newfd = %d\n", newfd);
	
	return 0;
}

