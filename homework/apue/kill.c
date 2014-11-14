/* 通过名字kill进程
 * ps -eo comm,pid
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


int is_name_equal(char* buff, char* name){
	int i = 0;
	int ret;
	while(*(buff + i) != ' ')
		i++;
	*(buff + i) = 0;

	ret = strcmp(buff, name);

	*(buff + i) = ' ';

	return ret ? 0 : 1;
}

void do_kill(char* buff, char* sig){
	int i;
	pid_t pid;
	int signo;

	for(i = 0; *(buff + i); i++){
		if(*(buff + i) >= '0' && *(buff + i) <= '9')
			break;
	}

	pid = atoi(buff + i);
	signo = atoi(sig);

	if(kill(pid, signo) < 0){
		perror("kill");
		return;
	}
}

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("usage: %s <process name> <signo>\n", argv[0]);
		exit(0);
	}

	FILE* fp;
	char buff[128];

	if((fp = popen("ps -eo comm,pid", "r")) == NULL){
		perror("popen");
		exit(1);
	}

	while(fgets(buff, sizeof(buff), fp)){
		if(is_name_equal(buff, argv[1])){
			do_kill(buff, argv[2]);
		}
	}


	return 0;
}

