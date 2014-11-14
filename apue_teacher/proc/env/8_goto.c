#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

//goto语句只能应用于函数内部的跳转
//不能跨函数使用

int fun()
{
ERR:
		perror("open()");
		exit(1);
}

int main(int argc, char *argv[])
{
	
	int fd,fd1,fd2;

	

	fd = open(argv[1], O_WRONLY);
	if(fd < 0){
		goto ERR;
	}
	
	fd1 = open(argv[2], O_WRONLY);
	if(fd1 < 0){
		goto ERR;
	}

	fd2 = open(argv[3], O_WRONLY);
	if(fd2 < 0){
		goto ERR;
	}
/*
ERR:
		perror("open()");
		exit(1);
*/

	return 0;
}


