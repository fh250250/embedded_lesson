#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(int argc, char* argv[]){
	
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	char* data = "I miss you";
	
	struct sockaddr_in client;
	client.sin_family = AF_INET;
	client.sin_port = htons(7788);
	client.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(fd, (struct sockaddr*)&client, sizeof(client)) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}

	int ret = send(fd, data, strlen(data), 0);
	if(ret < 0){
		perror("send");
		exit(EXIT_FAILURE);
	}
	printf("ret = %d\n", ret);

	return 0;
}

