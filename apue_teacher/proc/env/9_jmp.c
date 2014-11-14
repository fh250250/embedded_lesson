#include <stdio.h>
#include <setjmp.h>
#include <fcntl.h>

jmp_buf env;

void c(void)
{
	int fd;

	printf("fun c is run!\n");
	fd = open("file", O_WRONLY);
	if(fd < 0){
		longjmp(env, 100);
	}


}
void b(void)
{
	c();
	printf("fun b is run!\n");
}


void a(void)
{
	b();
	printf("fun a is run!\n");
}
int main(void)
{
	int ret;
	
	ret = setjmp(env);
	if(ret == 0){
		printf("ret = %d\n", ret);
		a();

	}else{ 
		printf("ret = %d\n", ret);	
	}

	return 0;
}

