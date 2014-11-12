#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc, char* argv[]){


	pid_t pid;
	if((pid = vfork()) < 0){
		perror("fork");
		exit(1);
	}else if(pid == 0){
		printf("child:  pid = %d\n", getpid());
		execlp("ls", "ls", NULL);
	}else{
		printf("parent: pid = %d\n", getpid());
	}

	return 0;
}

