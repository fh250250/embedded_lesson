#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>


int main(int argc, char const *argv[])
{
	char buf[256];
	int fl;

	fl = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, fl | O_NONBLOCK);



	struct pollfd fds[1];


	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;


	while(1){

		poll(fds, 1, 2000);


		printf("read before\n");

		read(STDIN_FILENO, buf, sizeof(buf));

		printf("read after\n\n\n");
	}

	fcntl(STDIN_FILENO, F_SETFL, fl);
	
	return 0;
}
