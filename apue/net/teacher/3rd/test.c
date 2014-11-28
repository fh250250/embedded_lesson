#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef unsigned char __u8;
typedef unsigned short __be16;
typedef unsigned short __sum16;
typedef unsigned long __be32;

struct ether_header {
	unsigned char    ether_dhost[6];
	unsigned char    ether_shost[6];
	ushort   ether_type;
};

#define __LITTLE_ENDIAN_BITFIELD	1

struct iphdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
        __u8    ihl:4,
                version:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
        __u8    version:4,
                ihl:4;
#endif
        __u8    tos;
        __be16  tot_len;
        __be16  id;
        __be16  frag_off;
        __u8    ttl;
        __u8    protocol;
        __sum16 check;
        __be32  saddr;
        __be32  daddr;
};

struct udphdr {
         __be16  source;
         __be16  dest;
         __be16  len;
         __sum16 check; 
};

void show_mac(char *buf);
void show_ip(char *buf);
void show_udp(char *buf);
void show_tcp(char *buf);
void show_app(char *buf);

int main()
{
	// char *data = "I miss you"; 
	char buf[512] = {
    0x00, 0x22, 0xfa, 0xaf, 0xde, 0x26, 0x00, 0x12, 0x7b, 0x62, 0x2a, 0xce,
    0x08, 0x00, 0x45, 0x00, 0x00, 0x26, 0x00, 0x00, 0x40, 0x00, 0x40, 0x11,
    0xb6, 0x87, 0xc0, 0xa8, 0x01, 0x6e, 0xc0, 0xa8, 0x01, 0x81, 0xed, 0x0e, 
    0x1e, 0x6c, 0x00, 0x12, 0xb6, 0x23, 0x49, 0x20, 0x6d, 0x69, 0x73, 0x73,
    0x20, 0x79, 0x6f, 0x75,                                  
	};
	show_mac(buf);
};
void show_mac(char *buf)
{
	struct ether_header *mac = (struct ether_header*)buf;
	printf("------ MAC --------\n");
	printf("dest: %02x:%02x:%02x:%02x:%02x:%02x\n", mac->ether_dhost[0],
	mac->ether_dhost[1],mac->ether_dhost[2],
	mac->ether_dhost[3],mac->ether_dhost[4],
	mac->ether_dhost[5]);

	printf("src: %02x:%02x:%02x:%02x:%02x:%02x\n", mac->ether_shost[0],
	mac->ether_shost[1],mac->ether_shost[2],
	mac->ether_shost[3],mac->ether_shost[4],
	mac->ether_shost[5]);
	printf("protocol: %02x\n", mac->ether_type);
	show_ip(buf + sizeof(struct ether_header));		
}
void show_ip(char *buf)
{
	printf("----- IP -------\n");
	struct iphdr *ip = (struct iphdr*)buf;
	printf("version: %d\n", ip->version);	
	printf("ihl: %d\n", ip->ihl);	
	printf("tot_len: %d\n", ntohs(ip->tot_len));	
	unsigned short ret = ntohs(ip->frag_off);
	printf("frag_off: %d\n",(ret &(~0x1fff)) >> 13);	
	printf("ttl: %d\n", ip->ttl);		
	printf("protocol: %d\n", ip->protocol);
	printf("check: 0x%x\n", ntohs(ip->check));		

	struct in_addr src, dest;
	src.s_addr = ip->saddr;
	dest.s_addr = ip->daddr;
	printf("src ip: %s\n", inet_ntoa(src));		
	printf("dest ip: %s\n", inet_ntoa(dest));		

	if(ip->protocol == 17)
		show_udp(buf + sizeof(struct iphdr));
	if(ip->protocol == 6)
		show_tcp(buf + sizeof(struct iphdr));
}
void show_udp(char *buf)
{
	printf("------ UDP ------ \n");	
	struct udphdr *udp = (struct udphdr *)buf;
	printf("source port: %d\n", ntohs(udp->source));	
	printf("dest port: %d\n", ntohs(udp->dest));	
	printf("len: %d\n", ntohs(udp->len));	
	printf("check sum: %x\n", ntohs(udp->check));	
	show_app(buf + sizeof(struct udphdr));
}
void show_app(char *buf)
{
	printf("---------  APP -------------\n");
	printf("data: %s\n", buf);
}
void show_tcp(char *buf)
{
	printf("------ TCP ------ \n");	
}





















