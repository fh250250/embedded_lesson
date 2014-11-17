#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>


struct msgbuf {
	long mtype;
	char mtext[256];
};


int main(int argc, char* argv){

	key_t key = ftok("/etc/profile", 2);
	if(key < 0){
		perror("ftok");
		exit(EXIT_FAILURE);
	}

	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid < 0){
		perror("msgget");
		exit(EXIT_FAILURE);
	}


	struct msgbuf msg;
	for(;;){
		if(msgrcv(msgid, &msg, sizeof(msg.mtext), 0, 0) < 0){
			perror("msgrcv");
			exit(EXIT_FAILURE);
		}

		printf("%s", msg.mtext);

		if(strcmp(msg.mtext, "quit\n") == 0){
			msgctl(msgid, IPC_RMID, NULL);
			break;
		}
	}

	return 0;
}

