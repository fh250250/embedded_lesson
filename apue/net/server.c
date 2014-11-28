#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(7788);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(fd, (struct sockaddr*)&server, sizeof(server)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if(listen(fd, 10) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in src;
	int len = 16;
	int nfd = accept(fd, (struct sockaddr*)&src, &len);
	if(nfd < 0){
		perror("accept");
		exit(EXIT_FAILURE);
	}

	printf("nfd = %d\n", nfd);


	char buf[256] = {0};
	int ret = recv(nfd, buf, sizeof(buf), 0);

	if(ret < 0){
		perror("recv");
		exit(EXIT_FAILURE);
	}
	printf("ret = %d\n", ret);
	printf("buf = %s\n", buf);

	return 0;
}

