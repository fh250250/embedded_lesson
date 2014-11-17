#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msgbuf {
	long mtype;
	char mtext[512];
};

int main(){

	key_t key = ftok("/etc/profile", 1);
	if(key < 0){
		perror("ftok err");
		exit(EXIT_FAILURE);
	}
	printf("key : %d\n", key);


	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid < 0){
		perror("msgget err");
		exit(EXIT_FAILURE);
	}
	printf("msgid : %d\n", msgid);


	struct msgbuf msg;
	
	if(msgrcv(msgid, &msg, 12, 0, IPC_NOWAIT) < 0){
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}

	if(msgctl(msgid, IPC_RMID, NULL) < 0){
		perror("msg remove");
		exit(EXIT_FAILURE);
	}

	return 0;
}

