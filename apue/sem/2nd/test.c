#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <string.h>

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO	*/
};

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
	union semun sem;
	sem.val = 1;	
	int ret = semctl(semid, 0, SETVAL, sem);
	if(ret < 0){
		perror("semctl err\n");
		exit(EXIT_FAILURE);
	}
	printf("sem init ok\n");
	return 0;
}
















