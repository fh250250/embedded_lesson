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
	msg.mtype = 1;

	for(;;){
		printf("send> ");
		if(!fgets(msg.mtext, sizeof(msg.mtext), stdin)){
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		if(msgsnd(msgid, &msg, sizeof(msg.mtext), IPC_NOWAIT) < 0){
			perror("msgsnd");
			exit(EXIT_FAILURE);
		}

		if(strcmp(msg.mtext, "quit\n") == 0){
			break;
		}
	}

	return 0;
}

