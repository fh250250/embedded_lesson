#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

	int fd;
	fd = open(argv[1], O_RDWR|O_TRUNC);
	if(fd < 0){
		perror("open");
		exit(1);
	}



	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}else if(pid == 0){
		// printf("child:  pid = %d, ppid = %d\n", getpid(), getppid());
		write(fd, "hello world!", 12);
	}else{
		// printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(1);
		int ret;
		ret = lseek(fd, 0, SEEK_CUR);
		printf("ret = %d\n", ret);
	}

	printf("@@@ pid = %d, ppid = %d\n", getpid(), getppid());

	return 0;
}

