#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <poll.h>


int main(int argc, char const *argv[])
{
	int fd10, fd11;
	char buf[256] = {0};


	fd10 = open("/dev/tty10", O_RDWR);
	fd11 = open("/dev/tty11", O_RDWR);


	if(fd10 < 0 || fd11 < 0){
		perror("open");
		exit(1);
	}


	int flag10;
	flag10 = fcntl(fd10, F_GETFL);
	fcntl(fd10, F_SETFL, flag10 | O_NONBLOCK);

	int flag11;
	flag11 = fcntl(fd11, F_GETFL);
	fcntl(fd11, F_SETFL, flag11 | O_NONBLOCK);



	// fd_set rfds;



	struct pollfd fds[2];

	fds[0].fd = fd10;
	fds[0].events = POLLIN;

	fds[1].fd = fd11;
	fds[1].events = POLLIN;



	int ret;
	write(fd10, "\n\n   TTY10\n\n\n", 14);
	write(fd11, "\n\n   TTY11\n\n\n", 14);
	for(;;){


		poll(fds, sizeof(fds)/sizeof(struct pollfd), -1);

		// FD_ZERO(&rfds);
		// FD_SET(fd10, &rfds);
		// FD_SET(fd11, &rfds);
		// select(fd11 + 1, &rfds, NULL, NULL, NULL);



		ret = read(fd10, buf, sizeof(buf));
		if(ret < 0){

			if(errno != EAGAIN){
				perror("read");
				exit(1);
			}

		}else if(ret == 0){
			break;
		}else {
			write(fd11, buf, ret);
		}

		ret = read(fd11, buf, sizeof(buf));
		if(ret < 0){

			if(errno != EAGAIN){
				perror("read");
				exit(1);
			}
			
		}else if(ret == 0){
			break;
		}else {
			write(fd10, buf, ret);
		}
	}


	fcntl(fd10, F_SETFL, flag10);
	fcntl(fd11, F_SETFL, flag11);

	close(fd10);
	close(fd11);
	
	return 0;
}
