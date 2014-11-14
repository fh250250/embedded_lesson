#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

void sig_alarm(int signo){
	alarm(1);
}


int main(int argc, char* argv[]){
	int fd;
	char buf[10];
	
	signal(SIGALRM, sig_alarm);

	fd = open(argv[1], O_RDONLY);

	alarm(1);
	for(;;){
		if(!write(STDOUT_FILENO, buf, read(fd, buf, sizeof(buf))))
			break;
		pause();
	}

	return 0;
}
