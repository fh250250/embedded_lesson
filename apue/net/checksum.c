#include <stdio.h>

unsigned short checksum(unsigned char* headers);
int is_big_mod();

int main()
{
	//b8ec
	unsigned char headers[20] = {
	0x45, 0x00, 0x00, 0x20, 0x00, 0x00, 0x40, 0x00, 
	0x40, 0x11, 0x00, 0x00, 0xc0, 0xa8, 0x00, 0x08, 
	0xc0, 0xa8, 0x00, 0x88
	};
	
	unsigned short ret = checksum(headers);
	printf("check sum is %x\n", ret);
}

unsigned short checksum(unsigned char* headers){
	unsigned short sum = 0;
	int i;

	headers[10] = 0;
	headers[11] = 0;

	if(is_big_mod()){
		unsigned char* p = headers;
		for(i = 0; i < 20; i++){
			if(i%2){
				sum += ~((*(p + i - 1) << 8) | *(p + i));
			}
		}
	}else {
		unsigned short* p = (unsigned short*)headers;
		for(i = 0; i < 10; i++){
			sum += ~(*(p + i));
		}
	}

	return sum;
}

int is_big_mod(){
	int a = 1;
	int* p = &a;

	if( *((char*)p + 3) )
		return 0;

	return 1;
}

