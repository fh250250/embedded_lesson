#include "main.h"

Node* newNode(){
	Node* node = NULL;

	node = malloc(sizeof(Node));
	if(node == NULL){
#if DEBUG == 1
		printf("内存不足\n");
#endif
		exit(-1);
	}

#if DEBUG == 1
	printf("Node 分配内存成功\n");
#endif

	// 初始化
	node->student = newStudent();
	node->next = NULL;

	return node;
}

void delNode(Node** node){
	if(*node != NULL){
		delStudent( &((*node)->student) );

		free(*node);

#if DEBUG == 1
		printf("Node 已释放\n");
#endif

		*node = NULL;
	}
}

SingleChain* newSingleChain(){
	SingleChain* single_chain = NULL;

	single_chain = malloc(sizeof(SingleChain));
	if(single_chain == NULL){

#if DEBUG == 1
	printf("内存不足\n");
#endif
		exit(-1);
	}

#if DEBUG == 1
	printf("SingleChain 分配内存成功\n");
#endif

	single_chain->len = 0;
	single_chain->head = newNode();

	return single_chain;
}

void push(SingleChain* single_chain, Node* node){
	Node* origin_first = single_chain->head->next;
	single_chain->head->next = node;
	node->next = origin_first;

	single_chain->len++;

#if DEBUG == 1
	printf("push a node at front, length is %lu\n", single_chain->len);
#endif
}

void pop(SingleChain* single_chain){
	if(single_chain->head->next != NULL){
		Node* first = single_chain->head->next;
		single_chain->head->next = first->next;

		delNode(&first);

		single_chain->len--;

#if DEBUG == 1
		printf("pop a node at front, length is %lu\n", single_chain->len);
#endif
	}
}

void empty(SingleChain* single_chain){
	if(single_chain->len > 0){
		while(single_chain->head->next != NULL){
			pop(single_chain);
		}
	}
#if DEBUG == 1
	printf("链表已清空,length = %lu\n", single_chain->len);
#endif
}


void delSingleChain(SingleChain** single_chain){
	if(*single_chain != NULL){
		empty(*single_chain);

		free(*single_chain);

#if DEBUG == 1
		printf("SingleChain 已释放\n");
#endif

		*single_chain = NULL;
	}
}
