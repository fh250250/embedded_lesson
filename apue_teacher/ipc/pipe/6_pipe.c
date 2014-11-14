#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
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
	}else if(pid > 0){
		//父(写)-->子(读)
		close(pfd[0]);
		while(1){
			write(pfd[1], "hello world!\n", 14);
			sleep(1);
		}
		close(pfd[1]);
	}else{
		close(pfd[1]);
		while(1){
			ret = read(pfd[0], buf, sizeof(buf));
			write(1, buf, ret);
			sleep(1);
		}
		close(pfd[0]);
	}


	return 0;
}



