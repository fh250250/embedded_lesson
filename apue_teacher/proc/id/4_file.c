#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//父子进程共享文件指针

int main(int argc , char *argv[])
{
	int fd;
	pid_t pid;

	fd = open(argv[1], O_RDWR|O_TRUNC);
	if(fd < 0){
		perror("open()");
		exit(1);
	}

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		write(fd, "hello world!", 12);
		
	}else{
		sleep(1);
		int ret;
		ret = lseek(fd, 0, SEEK_CUR);
		printf("ret = %d\n", ret);
	}

	return 0;
}

