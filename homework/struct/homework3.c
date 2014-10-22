/*
 * Author:   段鹏远
 * Version:  0.1
 * Time:     2014-10-16
 * Function: N个人围成一圈，从一开始数，数到M的人退出，下一个人重新开始数，直到剩下最后一个人。
 * 			 要求： N M由键盘输入，使用带头的单循环链表实现
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	size_t id;
	struct Node* next;
};
typedef struct Node Node;

Node* initChain();
void add_to_chain(Node* head, size_t n);
void show_chain(Node* head);
void run(Node* head, size_t n, size_t m);

int main(int argc, char const *argv[])
{
	size_t m, n;
	printf("Input N: ");
	scanf("%lu", &n);
	printf("and M: ");
	scanf("%lu", &m);

	Node* chain = initChain();

	add_to_chain(chain, n);
	show_chain(chain);

	run(chain, n, m);
	show_chain(chain);
	
	return 0;
}

Node* initChain(){
	Node* head = NULL;
	head = malloc(sizeof(Node));
	if(head == NULL){
		exit(-1);
	}

	head->id = 0;
	head->next = head;

	return head;
}

void add_to_chain(Node* head, size_t n){
	size_t i;
	Node* node;
	Node* tail = head;
	for(i = 0; i < n; i++){
		node = malloc(sizeof(Node));
		if(node == NULL){
			exit(-1);
		}

		node->id = i+1;
		tail->next = node;
		node->next = head;
		tail = node;
	}
}

void show_chain(Node* head){
	Node* cur = head;
	while(cur->next != head){
		printf("%lu ", cur->next->id);
		cur = cur->next;
	}
	printf("\n");
}

void run(Node* head, size_t n, size_t m){
	Node* cur = head;
	Node* node;
	size_t count = 1;

	while(n > 1){
		if(cur->next == head){
			cur = cur->next;
			continue;
		}

		if(count == m){
			node = cur->next;
			cur->next = cur->next->next;

			if(node != NULL){
				// printf("%lu\n", node->id);
				free(node);
			}

			n--;
			count = 1;
			continue;
		}

		cur = cur->next;
		count++;
	}
}
