#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>

int  main()
{
	key_t key = ftok("/etc/profile", 1);
	if(key < 0){
		perror("ftok err\n");
		exit(EXIT_FAILURE);
	}
	int semid = semget(key, 1, IPC_CREAT | 0666);
	if(semid < 0){
		perror("semget err\n");
		exit(EXIT_FAILURE);
	}
	printf("semid: %d\n", semid);

	return 0;
}
















