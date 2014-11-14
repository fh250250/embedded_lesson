#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>

void fun(int signo)
{
	printf("SIGPIPE = %d\n", signo);
}

int main(void)
{
	int i;
	int fd;
	int ret;
	char buf[256];

	signal(SIGPIPE, fun);

	printf("open before!\n");
	fd = open("file", O_WRONLY);
	if(fd < 0){
		perror("open()");
	}
	printf("open after!\n");

	for(i = 0; i <= 3; i++){
		write(fd, "hello world!\n", 14);
		printf("i = %d\n", i);
		sleep(1);
	}
	while(1)
		sleep(1);
	printf("write end!\n");


	return 0;
}

