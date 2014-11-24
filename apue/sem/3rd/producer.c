#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/sem.h>

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO	*/
};
#if 0
struct sembuf {
	unsigned short sem_num;  /* semaphore number */
	short          sem_op;   /* semaphore operation */
	short          sem_flg;  /* operation flags */
};
#endif
int create(int *pkey)
{
	*pkey = ftok("/etc/profile", 1);
	if(*pkey < 0){
		perror("ftok err\n");
		exit(EXIT_FAILURE);
	}
	int semid = semget(*pkey, 1, IPC_CREAT | 0666);
	if(semid < 0){
		perror("semget err\n");
		exit(EXIT_FAILURE);
	}
	return semid;	
}
int init_sem(int semid)
{
	union semun sem;
	sem.val = 1;	
	int ret = semctl(semid, 0, SETVAL, sem);
	if(ret < 0){
		perror("semctl err\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
int sem_p(int semid)
{
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = -1;
	buf.sem_flg = SEM_UNDO;

	int ret = semop(semid, &buf, 1);
	if(ret < 0){
		perror("semop err\n");
		exit(EXIT_FAILURE);
	}
}
int sem_v(int semid)
{
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = 1;
	buf.sem_flg = SEM_UNDO;

	int ret = semop(semid, &buf, 1);
	if(ret < 0){
		perror("semop err\n");
		exit(EXIT_FAILURE);
	}
}
int  main()
{
	key_t key = 0;
	int semid = create(&key);
	init_sem(semid);	
	int shmid = shmget(key, 4096, IPC_CREAT | 0666);
	if(shmid < 0){
		perror("shmget err\n");
		exit(EXIT_FAILURE);
	}
	char *addr = shmat(shmid, NULL, 0);
	if(addr == (void *)-1){
		perror("shmat err\n");
		exit(EXIT_FAILURE);
	}
	while(1){
		sem_p(semid);
		printf("sem_p \n");
		strcpy(addr, "hello world");
//		sem_v(semid);
		printf("sem_v\n");	
//		memset(addr, 0, 4096);
		sleep(1);
	}


	
		
}










