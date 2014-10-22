#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 1
void mem_creat(int** p, size_t size){

	*p = malloc(size);
	if(*p == NULL)
		exit(-1);
}

void mem_free(int** p){
	if(*p != NULL){
		free(*p);
		*p = NULL;
	}
}
#endif

#if 0
int** new_array(size_t row, size_t col);
void set_array(int** p, size_t row, size_t col);
void show_array(int** p, size_t row, size_t col);
#endif

int main(){

#if 1
	int* p = NULL;
	mem_creat(&p, 100);
	*p = 123;
	printf("%d\n", *p);

	mem_free(&p);

	printf("%p\n", p);
#endif

#if 0
	size_t row = 3, col = 4;

	int** p = new_array(row, col);

	//set_array(p, row, col);

	show_array(p, row, col);
#endif
}

#if 0
int** new_array(size_t row, size_t col){
	int** p = NULL;

	p = malloc(row * sizeof(int*));
	if(p == NULL){
		exit(-1);
	}

	memset(p, 0, row * sizeof(int*));

	int i;
	for(i = 0; i < row; i++){
		*(p + i) = malloc(col * sizeof(int));
		if(*(p + i) == NULL){
			exit(-1);
		}

		memset(*(p + i), 0, col * sizeof(int));
	}

	return p;
}
void set_array(int** p, size_t row, size_t col){
	
}
void show_array(int** p, size_t row, size_t col){
	int i, j;

	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%5d", *(*(p + row) + col) );
		}
		printf("\n");
	}
}
#endif

