#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(fd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in udpr;
	udpr.sin_family = AF_INET;
	udpr.sin_port = htons(7788);
	udpr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(fd, (struct sockaddr*)&udpr, sizeof(udpr)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}


	char buf[256] = {0};
	struct sockaddr_in src;
	int len;
	int ret = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr*)&src, &len);

	if(ret < 0){
		perror("recvfrom");
		exit(EXIT_FAILURE);
	}
	printf("ret = %d\n", ret);
	printf("buf = %s\n", buf);

	return 0;
}

