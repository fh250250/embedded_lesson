/*
 * Author:   段鹏远
 * Version:  0.1
 * Time:     2014-10-16
 * Function: 建立两个双循环链表：
 * 				（4.1 将两个双循环链表链接成一个双循环链表。
 * 				（4.2 将其中的一条双循环链表插在另一条链表的任意两个节点中间
 * 				（4.3 将其中的一条双循环链表的某个节点取出来，插到另一条链表的某个节点后面。
 */

#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int data;
	struct node_t* prev;
	struct node_t* next;
};
typedef struct node_t node_t;

node_t* initChain();
void add_head(node_t* head, size_t len);
void show_chain(node_t* head);
node_t* combine(node_t* head1, node_t* head2);


int main(int argc, char const *argv[])
{
	node_t* chain1 = initChain();
	add_head(chain1, 10);
	printf("chain1: ");
	show_chain(chain1);

	node_t* chain2 = initChain();
	add_head(chain2, 5);
	printf("chain2: ");
	show_chain(chain2);


	node_t* chain3 = combine(chain1, chain2);
	printf("chain3: ");
	show_chain(chain3);
	
	return 0;
}

node_t* initChain(){
	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	if(head == NULL){
		exit(-1);
	}

	head->data = 0;
	head->prev = head;
	head->next = head;

	return head;
}

void add_head(node_t* head, size_t len){
	size_t i;
	node_t* new_node;

	for(i = 0; i < len; i++){
		new_node = malloc(sizeof(node_t));
		if(new_node == NULL){
			exit(-1);
		}

		new_node->data = i+1;

		new_node->next = head->next;
		head->next->prev = new_node;
		head->next = new_node;
		new_node->prev = head;
	}
}

void show_chain(node_t* head){
	node_t* cur = head;

	while(cur->next != head){
		printf("%d ", cur->next->data);
		cur = cur->next;
	}
	printf("\n");
}

node_t* combine(node_t* head1, node_t* head2){
	head1->prev->next = head2->next;
	head2->next->prev = head1->prev;

	head1->prev = head2->prev;
	head2->prev->next = head1;

	return head1;
}
