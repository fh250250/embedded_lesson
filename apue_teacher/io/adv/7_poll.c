#include <stdio.h>
#include <fcntl.h>
#include <poll.h>

int main(void)
{
	char buf[256];	
	int fl;	
	struct pollfd fds[1];	

	fl = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, fl|O_NONBLOCK);

	while(1){
		fds[0].fd = 0;		
		fds[0].events = POLLIN;

		poll(fds, 1, 2000);

		printf("read_before\n");

		read(0, buf, sizeof(buf));
		
		printf("read_after\n\n\n");
	}

	fcntl(0, F_SETFL, fl);

	return 0;
}
