#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[256];
	

	fp = fopen(argv[1], "r");	
	
	fgets(buf, sizeof(buf), fp);

	printf("buf = %s",buf);

	printf("buf[%d] = %d\n",strlen(buf),buf[strlen(buf)]);

	return 0;
}

