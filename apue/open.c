#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int src, dest;
	char buf[256];
	int ret;

	src = open(argv[1], O_RDONLY);
	if(src < 0){
		perror("open()");
		exit(1);
	}

/*
	dest = open(argv[2], O_WRONLY|O_APPEND);
	if(dest < 0){
		perror("open()");
		exit(1);
	}
*/

	dest = STDOUT_FILENO;

	for(;;){
		ret = read(src, buf, sizeof(buf));
		if(ret == 0)
			break;

		write(dest, buf, ret);
	}

	return 0;
}

