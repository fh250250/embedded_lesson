#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ret;	
	
	char *arg[10]={"ls", "-l", "-a", NULL};


	printf("exec start!\n");

	
	execv("ls", arg);
	//execvp("ls", arg);
		

	//第一个参数必须为命令完整路径
	/*
	ret = execl("/bin/ls", "ls", NULL);
	if(ret < 0){
		perror("execl()");
		exit(1);
	}
	*/
	//第一个参数可以只为命令名
	//execlp("ls", "ls", NULL);





	printf("exec end!\n");

	return 0;
}



