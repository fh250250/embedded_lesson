#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char buf[256];	
	int fl;	
	
	fl = fcntl(0, F_GETFL);
	fcntl(0, F_SETFL, fl|O_NONBLOCK);

	while(1){
		
		printf("read_before\n");

		read(0, buf, sizeof(buf));
		
		printf("read_after\n\n\n");
	}

	fcntl(0, F_SETFL, fl);

	return 0;
}
