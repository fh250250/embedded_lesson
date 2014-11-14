#include <stdio.h>

int main(void)
{
	
//srand 为rand函数设置种子，确保每次随机值不同
#if 0
	srand(getpid());
#else 
	srand(time(NULL));
#endif

	while(1){
		//rand函数用于产生随机值	
		printf("%d\n", rand()%10);
		
		sleep(1);
	}


	return 0;
}

