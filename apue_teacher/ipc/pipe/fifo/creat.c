#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ret;
	
	ret = mkfifo(argv[1], 0666);
	if(ret < 0){
		perror("mkfifo()");
		exit(1);
	}

	return 0;
}

