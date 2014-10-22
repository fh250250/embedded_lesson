#include "stack.h"

void memory_create(int** p, int size){
	*p = malloc(size * sizeof(int));
	if(*p == NULL){
		exit(-1);
	}
}

void init_stack(pstack_t p, int size){
	memory_create(&(p->bottom), size);
	p->top = 0;
}

int pop(pstack_t p, int* num){
	if((p->top) == 0){
		printf("empty");
		return 0;
	}
	p->top--;
	*num = p->bottom[p->top];
	return 1;
}

void push(pstack_t p, int num, int size){
	if((p->top) == size){
		printf("full\n");
		exit(-1);
	}

	p->bottom[p->top] = num;
	p->top++;
}

