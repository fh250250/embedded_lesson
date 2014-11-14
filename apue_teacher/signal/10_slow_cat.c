#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
void fun_alrm(int signo)
{
	alarm(1);
}
int main(int argc , char *argv[])
{
	int fd;
	int ret;
	char buf[10];	
	signal(SIGALRM , fun_alrm);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0 ){
		perror("open()");
		exit(1);
	}
	alarm(1);
	while(1){
		ret = read(fd, buf, sizeof(buf));
		if(ret == 0)
			break;
		write(1, buf, ret);
		pause();
	}
	return 0;
}


