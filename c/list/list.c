#include "list.h"
#include <stdio.h>

list* newList(){
	list* p = NULL;
	p = (list*)malloc(sizeof(list));
	
	if(p == NULL){
		printf("内存不足\n");
		exit(-1);
	}

	p->len = 0;
	p->head = NULL;

	return p;
}

node* newNode(){
	node* p = NULL;
	p = (node*)malloc(sizeof(node));
	if(p == NULL){
		printf("内存不足\n");
		exit(-1);
	}
	
	p->data = 0;
	p->next = NULL;
}

int insert(list* l, size_t index, int data){
	if(index > l->len){
		printf("插入位置[%lu]不存在\n", index);
		return 0;
	}

	node* n = newNode();
	n->data = data;

	if(index == 0){	// 插入最前端

		node* origin_first = l->head;
		l->head = n;
		n->next = origin_first;

	}else if(index == l->len){	// 插入末尾
		node* cur = l->head;
		
		for(;;){
			if(cur->next == NULL)
				break;
			cur = cur->next;
		}

		cur->next = n;
		n->next = NULL;

	}else{
		node* prev = NULL;
		node* cur = l->head;
		size_t i;

		for(i = 0; ; i++){
			if(i == index - 1){
				prev = cur;
				cur = cur->next;
				break;
			}

			cur = cur->next;
		}

		prev->next = n;
		n->next = cur;
	}

	l->len++;

	return 1;
}

void show(list* l){
	node* cur;
	for(cur = l->head; cur != NULL; cur = cur->next){
		printf("%4d", cur->data);
	}
	printf("\n");
}

int del(list* l, size_t index){

	if(index > l->len-1){
		printf("[%lu]处无元素\n", index);
		return 0;
	}

	if(index == 0){				// 删除最前端
		node* origin_first = l->head;
		l->head = l->head->next;

		if(origin_first != NULL){
			free(origin_first);
		}
	} else{

		node* prev = NULL;
		node* cur = l->head;
		size_t i;

		for(i = 0; ; i++){
			if(i == index - 1){
				prev = cur;
				cur = cur->next;
				break;
			}

			cur = cur->next;
		}

		prev->next = cur->next;

		if(cur != NULL){
			free(cur);
		}

	}

	l->len--;

	return 1;
}

node* get(list* l, size_t index){
	if(index > l->len-1){
		printf("[%lu]处无元素\n", index);
		return NULL;
	}

	node* cur;
	size_t i;
	for(i = 0, cur = l->head; i < index; i++, cur = cur->next);

	return cur;
}

void distory(list* l){
	if(l->len > 0){
		// 逐个释放
		while(l->len > 0){
			del(l, 0);		// 删除第一个
		}
	}

	if(l != NULL){
		free(l);
	}
}
