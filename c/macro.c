#include <stdio.h>

#define S(x) ((x)*(x))

#define _S_(a,b)  do{if((a)>(b)) printf("suss\n");else printf("fail\n");}while(0)

int main(){

	_S_(2, 1);
}

