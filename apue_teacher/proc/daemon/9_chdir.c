
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd;

	chdir("/root/APUE");

	fd = creat("file", 0666);


	return 0;
}


