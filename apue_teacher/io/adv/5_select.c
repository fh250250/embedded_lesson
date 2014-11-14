#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char buf[256];	
	int fl;	
	fd_set rfds;	
	struct timeval timeout;
	int ret;

	fl = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, fl|O_NONBLOCK);


	while(1){
		FD_ZERO(&rfds);		
		FD_SET(0, &rfds);
		
		timeout.tv_sec = 2;
		timeout.tv_usec = 0;
		
		ret = select(1, &rfds, NULL, NULL, NULL);
		
		printf("ret = %d\n", ret);
		printf("read_before\n");

		read(0, buf, sizeof(buf));
		
		printf("read_after\n\n\n");
	}

	fcntl(0, F_SETFL, fl);

	return 0;
}
