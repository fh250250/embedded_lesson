#include "../include/dname_stack.h"


dname_node* initStack(){
	dname_node* head = NULL;

	head = malloc(sizeof(dname_node));

	if(head == NULL){
		perror("没有足够内存\n");
		exit(-1);
	}

	head->dname = NULL;
	head->next = NULL;

	return head;
}


void push_stack(dname_node* head, const char* dname){
	dname_node* node = NULL;
	char* d_name = NULL;

	node = malloc(sizeof(dname_node));
	d_name = malloc(sizeof(char) * (strlen(dname) + 1) );

	if(!node || !d_name){
		perror("allocate mem failure\n");
		exit(-1);
	}

	node->next = head->next;
	head->next = node;

	strcpy(d_name, dname);
	node->dname = d_name;
}


char* pop_stack(dname_node* head){
	if(is_stack_empty(head)){
		return NULL;
	}

	dname_node* node = head->next;

	head->next = node->next;

	char* dname = node->dname;

	if(node){
		free(node);
	}

	return dname; // 注意名字占的空间未释放,在合适的地方释放
}


char is_stack_empty(dname_node* head){
	return head->next ? 0 : 1;
}

