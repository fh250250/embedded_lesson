#include "apue.h"

void fill(int** p){
	size_t i, j;

	for(i = 0; i < 5; i++)
		*(p + i) = malloc(5*sizeof(int));

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			*(*(p + i) + j) = (i+1)*(j+1);
		}
	}

	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%5d", *(*(p + i) + j));
		}
		printf("\n");
	}

}

int main(){
	//int* arr[5];

	int** arr = malloc(5*sizeof(int*));

	fill(arr);
}
