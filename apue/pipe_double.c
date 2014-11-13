#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

	int pipe_left[2];
	int pipe_right[2];

	if(pipe(pipe_left) < 0){
		perror("pipe");
		exit(1);
	}

	if(pipe(pipe_right) < 0){
		perror("pipe");
		exit(1);
	}


	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}

	if(pid == 0){	// 子进程
		close(pipe_left[0]);
		close(pipe_right[1]);
		char buf[256];
		int ret;

		for(;;){
			write(pipe_left[1], "I'am child\n", sizeof("I'am child\n"));
			ret = read(pipe_right[0], buf, sizeof(buf));
			write(STDOUT_FILENO, buf, ret);
			sleep(1);
		}
		
		close(pipe_left[1]);
		close(pipe_right[0]);
	} else{		// 父进程
		char buf[256];
		int ret;
		close(pipe_left[1]);
		close(pipe_right[0]);

		for(;;){
			write(pipe_right[1], "I'am father\n", sizeof("I'am father\n"));
			ret = read(pipe_left[0], buf, sizeof(buf));
			write(STDOUT_FILENO, buf, ret);
			sleep(1);
		}

		close(pipe_left[0]);
		close(pipe_right[1]);
	}


	return 0;
}

