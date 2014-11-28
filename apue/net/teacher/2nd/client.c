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
	char *data = "I miss you";	

	struct sockaddr_in tcp_client;

	tcp_client.sin_family = AF_INET;
	tcp_client.sin_port = htons(7788);
	tcp_client.sin_addr.s_addr = inet_addr("192.168.1.110");
	
	int ret = connect(fd, (struct sockaddr*)&tcp_client,
					 sizeof(tcp_client));	
	if(ret < 0){
		perror("connect err\n");
		exit(EXIT_FAILURE);
	}
	
	ret = send(fd, data, strlen(data), 0);
	if(ret < 0){
		perror("send err\n");
		exit(EXIT_FAILURE);
	}
	printf("ret: %d\n", ret);

	return 0;
}











