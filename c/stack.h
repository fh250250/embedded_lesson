#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_t {
	int* bottom;
	int top;
} stack_t, *pstack_t;

void init_stack(pstack_t p, int size);

int pop(pstack_t p, int* num);

void push(pstack_t p, int num, int size);

#endif

