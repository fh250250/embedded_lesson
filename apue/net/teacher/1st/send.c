#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

int main()
{
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(fd < 0){
		perror("socket err\n");
		exit(EXIT_FAILURE);
	}
	char *data = "I miss you";	
	struct sockaddr_in udps;
	udps.sin_family = AF_INET;
	udps.sin_port = htons(7788);
	udps.sin_addr.s_addr = inet_addr("192.168.1.110");
	
	int ret = sendto(fd, data, strlen(data), 0, 
	        	(struct sockaddr*)&udps, sizeof(udps));
	if(ret < 0){
		perror("sendto err\n");
		exit(EXIT_FAILURE);
	}
	printf("ret: %d\n", ret);
	
	return 0;
}











