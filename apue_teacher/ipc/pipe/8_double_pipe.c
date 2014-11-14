#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ret;
	pid_t pid;
	char buf[256];
	int father_to_child[2];
	int child_to_father[2];
	
	ret = pipe(father_to_child);
	if(ret < 0){
		perror("pipe()");
		exit(1);
	}

	ret = pipe(child_to_father);
	if(ret < 0){
		perror("pipe()");
		exit(1);
	}

	pid = fork();
	if(pid < 0){
		perror("fork()");
		exit(1);
	}else if(pid == 0){
		//子进程
		close(child_to_father[0]);
		close(father_to_child[1]);
		while(1){
			fgets(buf, sizeof(buf), stdin);
			write(child_to_father[1], buf, strlen(buf)+1);
			
			read(father_to_child[0], buf, sizeof(buf));
			printf("Father_to_child:\n");
			printf("%s\n",buf);			

		}		
		close(child_to_father[1]);
		close(father_to_child[0]);

	}else{
		close(child_to_father[1]);
		close(father_to_child[0]);
		while(1){
			read(child_to_father[0], buf, sizeof(buf));
			printf("Child_to_father:\n");
			printf("%s\n", buf);

			fgets(buf, sizeof(buf), stdin);
			write(father_to_child[1], buf, strlen(buf)+1);
		}
		close(child_to_father[0]);
		close(father_to_child[1]);
	}
	return 0;
}



