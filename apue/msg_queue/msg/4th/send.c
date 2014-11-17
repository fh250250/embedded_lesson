#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

struct msgbuf{
	long mtype;
	char mtext[512];
};

int main()
{
	key_t key = ftok("/etc/profile", 1);	
	if(key < 0){
		perror("ftok err\n");
		exit(EXIT_FAILURE);
	}
	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid < 0){
		perror("msgget err\n");
		exit(EXIT_FAILURE);
	}
	struct msgbuf msg;
	msg.mtype = 4;
	char *ps = "hello world";
	strcpy(msg.mtext, ps);

	//int ret = msgsnd(msgid, &msg, 12, IPC_NOWAIT);	
	int ret = msgsnd(msgid, &msg, 12, 0);	
	if(ret < 0){
		perror("msgsnd err\n");	
		exit(EXIT_FAILURE);
	}
	printf("msg: %s\n", msg.mtext);	

//-------------------------------------------------
	msg.mtype = 2;
	ps = "hello hebeigd";
	strcpy(msg.mtext, ps);
	ret = msgsnd(msgid, &msg, 20, 0);	
	if(ret < 0){
		perror("msgsnd err\n");	
		exit(EXIT_FAILURE);
	}
	
	printf("msg: %s\n", msg.mtext);	
	return 0;
}











