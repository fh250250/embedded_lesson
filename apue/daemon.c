#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}

	if(pid == 0){
		printf("[%d]\n", getpid());
		if(setsid() == -1){
			perror("setsid");
			exit(1);
		}
		if(chdir("/") == -1){
			perror("chdir");
			exit(1);
		}
		umask(0);
		
		int fd;
		
		if((fd = open("/dev/null", O_RDWR)) == -1){
			perror("open");
			exit(1);
		}

		if(dup2(fd, STDIN_FILENO)  == -1 ||
		   dup2(fd, STDOUT_FILENO) == -1 ||
		   dup2(fd, STDERR_FILENO) == -1 ){

			perror("dup2");
			exit(1);
		}
		close(fd);

		FILE* fp = fopen("/tmp/file.log", "w");
		if(fp == NULL){
			perror("fopen");
			exit(1);
		}

		for(;;){
			if( fprintf(fp, "%d\n", rand()) < 0){
				perror("fprintf");
				exit(1);
			}

			fflush(fp);

			sleep(1);
		}
	}

	return 0;
}

