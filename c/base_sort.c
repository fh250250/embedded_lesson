// 基数排序

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node_t
{
	int data;
	struct node_t* next;
};
typedef struct node_t node_t;

node_t* initChain();
void get_data(node_t* head, size_t n, size_t max);
void show_chain(node_t* head);
void dispatch(node_t* head, node_t** base, size_t level);
void combine(node_t* head, node_t** base);



int main(int argc, char const *argv[])
{
	node_t* base[10] = {NULL};

	node_t* chain = initChain();
	size_t n, max;

	printf("Input how much data do U want> ");
	scanf("%lu", &n);
	printf("and the Max limit> ");
	scanf("%lu", &max);

	get_data(chain, n, max);
	show_chain(chain);
	
	size_t level;
	for(level = 1; max > 0; max /= 10, level *= 10){
		dispatch(chain, base, level);
		combine(chain, base);
	}

	show_chain(chain);
	

	return 0;
}

node_t* initChain(){
	node_t* head = NULL;
	head = malloc(sizeof(node_t));

	if(head == NULL){
		exit(-1);
	}

	head->data = 0;
	head->next = NULL;

	return head;
}

// 产生随机数据填充链表
void get_data(node_t* head, size_t n, size_t max){
	size_t i;
	node_t* node;
	srand((unsigned int)time(0));

	for(i = 0; i < n; i++){
		node = malloc(sizeof(node_t));
		if(node == NULL){
			exit(-1);
		}

		node->data = rand() % max;

		node->next = head->next;
		head->next = node;
	}
}

void show_chain(node_t* head){
	node_t* cur = head;

	while(cur->next != NULL){
		printf("%d ", cur->next->data);

		cur = cur->next;
	}
	printf("\n");
}

// 分发
void dispatch(node_t* head, node_t** base, size_t level){
	node_t* node;
	node_t* cur;
	size_t index;

	while(head->next != NULL){
		node = head->next;
		head->next = node->next;
		node->next = NULL;

		index = (node->data / level) % 10;

		if(base[index] == NULL){
			base[index] = node;
		}else{
			for(cur = base[index]; cur->next != NULL; cur = cur->next);
			cur->next = node;
		}

	}
}

// 收集
void combine(node_t* head, node_t** base){
	size_t i;
	node_t* cur = head;

	for(i = 0; i < 10; i++){
		if(base[i] != NULL){
			while(cur->next != NULL){
				cur = cur->next;
			}

			cur->next = base[i];
			base[i] = NULL;
		}
	}
}
