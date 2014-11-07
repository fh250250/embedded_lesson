#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>


int main(int argc, char const *argv[])
{
	// char buf[256];
	int fl;
	fd_set rfds;
	struct timeval timeout;

	fl = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, fl | O_NONBLOCK);


	while(1){

		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO, &rfds);
		timeout.tv_sec = 2;
		timeout.tv_usec = 0;

		select(1, &rfds, NULL, NULL, /*&timeout*/NULL);

	}

	fcntl(STDIN_FILENO, F_SETFL, fl);
	
	return 0;
}
