#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(int argc, char* argv[]){
	
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(fd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	char* data = "I miss you";
	
	struct sockaddr_in udps;
	udps.sin_family = AF_INET;
	udps.sin_port = htons(7788);
	udps.sin_addr.s_addr = inet_addr(argv[1]);

	int ret = sendto(fd, data, strlen(data), 0, (struct sockaddr*)&udps, sizeof(udps));

	if(ret < 0){
		perror("sendto");
		exit(EXIT_FAILURE);
	}

	printf("ret = %d\n", ret);


	return 0;
}

