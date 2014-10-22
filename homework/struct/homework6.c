// 把一个大于0的十进制数转换成2进制数，使用栈

#include <stdio.h>
#include <stdlib.h>


struct node_t {
	char bit;
	struct node_t* next;
};
typedef struct node_t node_t;


node_t* initStack();

void push(node_t* head, char bit);

char pop(node_t* head);

void deal_it(unsigned int num);

char is_empty(node_t* head);




int main(int argc, char const *argv[])
{
	unsigned int num;

	printf("Input a digit> ");
	scanf("%u", &num);

	deal_it(num);
	
	return 0;
}


node_t* initStack(){
	node_t* head = NULL;

	head = malloc(sizeof(node_t));
	if(head == NULL){
		exit(-1);
	}

	head->bit = 0;
	head->next = NULL;

	return head;
}

void push(node_t* head, char bit){
	node_t* node = NULL;

	node = malloc(sizeof(node_t));
	if(node == NULL){
		exit(-1);
	}

	node->bit = bit?1:0;

	node->next = head->next;
	head->next = node;
}

char pop(node_t* head){
	if(is_empty(head)){	// stack empty
		return -1;
	}

	node_t* node;
	char bit;

	node = head->next;
	head->next = node->next;
	bit = node->bit;

	if(node != NULL){
		free(node);
	}

	return bit;
}


char is_empty(node_t* head){
	return head->next == NULL;
}


void deal_it(unsigned int num){
	node_t* stack = initStack();

	for(; num > 0; num /= 2){
		push(stack, (char)(num%2));
	}

	size_t align = 1;
	while(!is_empty(stack)){
		printf("%u", pop(stack));
		if(align%4 == 0) printf(" ");
		align++;
	}
	printf("\n");
}
