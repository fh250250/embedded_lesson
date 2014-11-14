#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int main(void)
{
	int a = 10;
	int b = 20;
	pid_t pid;

	pid = vfork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		a = add(a, b);
		printf("child pid = %d, a = %d\n\n",
										getpid(),a);
		exit(0);
	}else{
		printf("father a = %d\n",a);
		a = sub(a, b);
		printf("father pid = %d, a = %d\n",
									getpid(),a);
	}



	return 0;
}




