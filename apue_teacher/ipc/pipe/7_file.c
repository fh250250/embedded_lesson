#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc , char *argv[])
{
	int fd;
	int ret;
	pid_t pid;
	int pfd[2];
	char buf[256];

	ret = pipe(pfd);
	if(ret < 0){
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		close(pfd[0]);	
		
		fd = open(argv[1], O_RDONLY);
		if(fd < 0){
			perror("open()");
			exit(1);
		}
		while(1){
			ret = read(fd, buf, sizeof(buf));
			if(ret == 0)
				break;
			write(pfd[1], buf, ret);
		}
		close(pfd[1]);
	}else{
		close(pfd[1]);
		while(1){
			ret = read(pfd[0], buf, sizeof(buf));
			if(ret == 0)
				break;	
			write(1, buf, ret);
		}
		close(pfd[0]);
	}



	return 0;
}

