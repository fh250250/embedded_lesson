#include <stdio.h>
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
	struct msgbuf recvbuf;
	int ret = 0;	
//	ret = msgrcv(msgid, &recvbuf, 12, 0, IPC_NOWAIT);		
	ret = msgrcv(msgid, &recvbuf, 12, 0, 0);		
	if(ret < 0){
		perror("msgrcv err\n");
		exit(EXIT_FAILURE);
	}
	printf("recvbuf.mtext: %s\n", recvbuf.mtext);

	return 0;
}











