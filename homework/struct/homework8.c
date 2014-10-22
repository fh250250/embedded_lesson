// n!使用非递归

#include "apue.h"

// #define R

struct node_t {
	unsigned int n;
	struct node_t* next;
};
typedef struct node_t node_t;

node_t* initStack();
void push(node_t* head, unsigned int n);
unsigned int pop(node_t* head);
char is_empty(node_t* head);


unsigned int func(unsigned int n);



int main(int argc, char const *argv[])
{
	unsigned int n;

	printf("Input n> ");
	scanf("%u", &n);

	printf("%u! = %u\n", n, func(n));
	
	return 0;
}

node_t* initStack(){
	node_t* head = NULL;

	head = malloc(sizeof(node_t));
	if(head == NULL){
		exit(-1);
	}

	head->n = 0;
	head->next = NULL;

	return head;
}

void push(node_t* head, unsigned int n){
	node_t* node = NULL;

	node = malloc(sizeof(node_t));
	if(node == NULL){
		exit(-1);
	}

	node->n = n;

	node->next = head->next;
	head->next = node;
}

unsigned int pop(node_t* head){
	if(is_empty(head)){	// stack empty
		return 0;
	}

	node_t* node;
	unsigned int n;

	node = head->next;
	head->next = node->next;
	n = node->n;

	if(node != NULL){
		free(node);
	}

	return n;
}


char is_empty(node_t* head){
	return head->next == NULL;
}




#ifdef R

unsigned int func(unsigned int n){

	if(n == 0)
		return 1;
	else
		return n * func(n - 1);
}

#else

unsigned int func(unsigned int n){
	node_t* stack = initStack();

	if(n == 0)
		return 1;

	while(n > 0){
		push(stack, n);

		n--;
	}

	unsigned int sum = 1;

	while(!is_empty(stack)){
		sum *= pop(stack);
	}

	return sum;
}

#endif
