#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

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
		close(pfd[0]);

		for(;;){
			write(pfd[1], "hello world!\n", 14);
			sleep(1);
		}

		close(pfd[1]);
	} else{
		char* buf[256];
		int ret;
		close(pfd[1]);

		for(;;){
			ret = read(pfd[0], buf, sizeof(buf));

			write(STDOUT_FILENO, buf, ret);

			sleep(2);
		}

		close(pfd[0]);
	}


	return 0;
}

