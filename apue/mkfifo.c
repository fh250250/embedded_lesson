#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


int main(){

	int ret;
	ret = mkfifo("fifo.test", 0666);

	if(ret < 0){
		perror("mkfifo");
		exit(1);
	}

	return 0;
}
