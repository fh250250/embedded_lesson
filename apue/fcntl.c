#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	char buf[256];

	int fl;

	fl = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, fl | O_NONBLOCK);


	while(1){
		printf("read before\n");

		read(STDIN_FILENO, buf, sizeof(buf));

		printf("read after\n\n\n");
	}

	fcntl(STDIN_FILENO, F_SETFL, fl);
	
	return 0;
}
