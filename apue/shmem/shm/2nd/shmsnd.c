#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok("/etc/profile", 1);
	if(key < 0){
		perror("ftok err \n");
		exit(EXIT_FAILURE);
	}
	int shmid = shmget(key, 4096, IPC_CREAT | 0666);
	if(shmid < 0){
		perror("shmget err\n");
		exit(EXIT_FAILURE);
	}
	printf("shmid : %d\n", shmid);
	char *addr = shmat(shmid, NULL, 0);
	if(addr == (void *)-1){
		perror("shmat err\n");
		exit(EXIT_FAILURE);
	}
	strcpy(addr, "hello world");	
	
	sleep(8);
	printf("addr: %s\n", addr);
	
	return 0;
}












