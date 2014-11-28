#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd < 0){
		perror("socket err\n");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in udpr;
	udpr.sin_family = AF_INET;
	udpr.sin_port = htons(7788);
//	udpr.sin_addr.s_addr = inet_addr("192.168.1.110");
	udpr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int ret = bind(fd, (struct sockaddr*)&udpr, sizeof(udpr));
	if(ret < 0){
		perror("bind err\n");
		exit(EXIT_FAILURE);
	}
	ret = listen(fd, 10);
	if(ret < 0){
		perror("listen err\n");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in src;
	int len = 16;
	int nfd = accept(fd, (struct sockaddr*)&src, &len);	
	if(nfd < 0){
		perror("accept err\n");
		exit(EXIT_FAILURE);
	}
	printf("nfd: %d\n", nfd);
	printf("len: %d\n", len);

	char buf[256] = {0};
	ret = recv(nfd, buf, sizeof(buf), 0);	
	if(ret < 0){
		perror("recv err\n");	
		exit(EXIT_FAILURE);
	}
	printf("ret: %d\n", ret);
	printf("buf: %s\n", buf);
	
	return 0;	
}











