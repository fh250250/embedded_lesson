#include <stdio.h>
#include <net/ethernet.h>
#include <netinet/ip.h>

unsigned short check_sum(unsigned char *buff, int len);

int main()
{
	//b8ec
	unsigned char buff[1024] = {
	0x45, 0x00, 0x00, 0x20, 0x00, 0x00, 0x40, 0x00, 
	0x40, 0x11, 0x00, 0x00, 0xc0, 0xa8, 0x00, 0x08, 
	0xc0, 0xa8, 0x00, 0x88
	};
	
	unsigned short ret = 0;
	ret = check_sum(buff, 20);
	printf("check sum is %x\n", ret);
}

unsigned short check_sum(unsigned char *buff, int len)
{
	unsigned short *p = (unsigned short *)buff;
	unsigned long ret = 0;
	
	while(len > 1){
		ret = ret + ntohs(*p);
		p++;
		len = len - 2;
	}
	
	unsigned short data = (ret & 0xffff) + (ret >> 16);
	return ~data;
}













