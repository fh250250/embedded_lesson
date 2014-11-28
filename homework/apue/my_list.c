#include "my_list.h"


list_t* create_list(){
	node_t* head = NULL;
	
	head = malloc(sizeof(node_t));
	// malloc failure
	if (head == NULL) {
		return NULL;
	}
	
	head->data = 0;
	head->next = NULL;
	
	return head;
}

int insert_list(list_t* head, int where, int data){
	if (head == NULL || where < 0) {
		return ERR_ARG;
	}

	node_t* node = NULL;
	node = malloc(sizeof(node_t));
	if (node == NULL) {
		return ERR_MALLOC;
	}
	node->data = data;
	
	int i;
	node_t* cur;
	for (i = 0, cur = head; ; i++, cur = cur->next) {
		if(where == i){
			node->next = cur->next;
			cur->next = node;
			return 0;
		}
		
		if (cur->next == NULL) {
			cur->next = node;
			node->next = NULL;
			return 0;
		}
	}		
}

void print_list(list_t* list){
	node_t* cur = list;
	while (cur->next){
		printf("%d ", cur->next->data);
		cur = cur->next;
	}
	printf("\n");
}


list_t* reverse_list(list_t* head){
	if(head == NULL){
		return NULL;
	}

	node_t* cur = head;
	node_t* tail;

	while(cur->next->next){
		cur = cur->next;
	}
	tail = cur->next;

	while(head->next->next){
		cur->next->next = cur;
		cur->next = NULL;

		cur = head;
		while(cur->next->next){
			cur = cur->next;
		}
	}

	head->next = tail;
	return head;
}


int sort_list(list_t* head){
	if(head == NULL || head->next == NULL){
		return ERR_ARG;
	}

	list_t* sorted_list = NULL;
	node_t* sorted_list_tail = NULL;

	node_t* cur;
	node_t* min_prev;


	while(head->next){

		cur = head;
		min_prev = head;

		while(cur->next){
			if(cur->next->data < min_prev->next->data){
				min_prev = cur;
			}

			cur = cur->next;
		}

		cur = min_prev->next;
		min_prev->next = cur->next;

		if(sorted_list == NULL){
			sorted_list = cur;
		}else {
			sorted_list_tail->next = cur;
		}

		sorted_list_tail = cur;

	}

	head->next = sorted_list;

	return 0;
}
