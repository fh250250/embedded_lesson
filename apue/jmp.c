#include <stdio.h>
#include <setjmp.h>

jmp_buf env;



void func(){

	longjmp(env, 100);

	printf("0_0\n");
}


int main(){

	int ret;

	ret = setjmp(env);
	if(ret)
		printf("ret = %d\n", ret);
	else
		func();

	return 0;
}

