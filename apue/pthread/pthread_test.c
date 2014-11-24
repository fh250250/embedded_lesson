#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void* pthread_call_back(){
	printf("I'am in call back\n");

	return NULL;
}


int main(){
	
	pthread_t pthid;

	if(pthread_create(&pthid, NULL, pthread_call_back, NULL) != 0){
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}
	
	printf("I'am in main\n");

	if(pthread_join(pthid, NULL) != 0){
		perror("pthread_join");
		exit(EXIT_FAILURE);
	}

	return 0;
}

