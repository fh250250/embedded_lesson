#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

	int pfd[2];

	if(pipe(pfd) < 0){
		perror("pipe");
		exit(1);
	}

	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}

	if(pid > 0){ // 父进程
		close(pfd[1]);

		int ret;
		char buf[256];
		while((ret = read(pfd[0], buf, sizeof(buf))) != 0){
			write(STDOUT_FILENO, buf, ret);
		}

		close(pfd[0]);
	} else{ // 子进程

		int fd;
		char buf[256];
		int ret;
		close(pfd[0]);

		if((fd = open(argv[1], O_RDONLY)) < 0){
			perror("open");
			exit(1);
		}
		
		while((ret = read(fd, buf, sizeof(buf))) != 0){
			write(pfd[1], buf, ret);
		}

		close(fd);
		close(pfd[1]);
	}


	return 0;
}

