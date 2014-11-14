#include <stdio.h>
#include <time.h>

int main(void)
{
	int count = 0;
	time_t tms;

	tms = time(NULL);
#if 1
	while(tms != (time(NULL)-5)){
		count++;
	}
#else 
	while(time(NULL)-tms < 5){
		count++;
	}
#endif
	printf("count = %d\n", count);

	return 0;
}


