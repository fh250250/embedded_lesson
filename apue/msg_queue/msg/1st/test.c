#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

int main()
{
	key_t key = ftok("/etc/profile", 1);	
	if(key < 0){
		perror("ftok err\n");
		exit(EXIT_FAILURE);
	}
	printf("key: %d\n",key);
	//int msgid = msgget(key, IPC_CREAT |IPC_EXCL| 0666);
	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid < 0){
		perror("msgget err\n");
		exit(EXIT_FAILURE);
	}
	printf("msgid : %d\n", msgid);

	return 0;
}











