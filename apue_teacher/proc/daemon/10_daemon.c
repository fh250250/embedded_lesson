#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void my_daemon()
{
	int fd;
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}if(pid > 0){
		printf("child_pid:%d\n",pid);
		exit(0);
	}
	setsid();	
	chdir("/");
	umask(0);
	fd = open("/dev/null", O_RDWR);
	if(fd < 0){
		perror("open()");
		exit(1);
	}
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
}

int main(void)
{
//	printf("before!\n");

	int fd;
	char ch;
	
	my_daemon();
	
	fd = open("/tmp/file.log",O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd < 0){
		perror("open()");
		exit(1);
	}
//	printf("after!\n");
	srand(getpid());
	while(1){
		ch = '0' + rand()%10;
		write(fd, &ch, 1);		
		sleep(1);
	}


	return 0;
}





