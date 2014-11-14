#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <poll.h>

int relay(int fd10, int fd11)
{
	char buf[256];
	int ret;
	int fl10,fl11;
	int count =0;
	struct pollfd fds[2];

	fl10 = fcntl(fd10, F_GETFL);
	fl11 = fcntl(fd11, F_GETFL);

	fcntl(fd10, F_SETFL, fl10|O_NONBLOCK);
	fcntl(fd11, F_SETFL, fl11|O_NONBLOCK);

	while(1){
		fds[0].fd = fd10;
		fds[0].events = POLLIN;

		fds[1].fd = fd11;
		fds[1].events = POLLIN;

		poll(fds, 2 , -1);		

		ret = read(fd10, buf, sizeof(buf));
		if(ret < 0){
			if(errno == EAGAIN){
			}else{
				perror("read()");
				exit(1);
			}
		}else if(ret == 0){
			break;
		}else{
			write(fd11, buf, ret);
		}

		ret = read(fd11, buf, sizeof(buf));
		if(ret < 0){
			if(errno == EAGAIN){
			}else{
				perror("read()");
				exit(1);
			}
		}else if(ret == 0){
			break;
		}else{
			write(fd10, buf, ret);
		}
	
		printf("count = %d\n", count++);
	}	

	fcntl(fd10, F_SETFL, fl10);
	fcntl(fd11, F_SETFL, fl11);
}


int main(void)
{
	int fd10, fd11;

	fd10 = open("/dev/tty10", O_RDWR);
	if(fd10 < 0){
		perror("open()");
		exit(1);
	}
	fd11 = open("/dev/tty11", O_RDWR);
	if(fd11 < 0){
		perror("open()");
		exit(1);
	}

	write(fd10, "\nTTY10\n\n",8);
	write(fd11, "\nTTY11\n\n",8);

	relay(fd10, fd11);
	

	return 0;
}




