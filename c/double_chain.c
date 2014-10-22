/*
 *  带头双循环链表
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node* next;  // int* p   int *p
	struct node* prev;

};
void creat_memory(struct node** p)
{
	*p=malloc(sizeof(struct node));
		if(*p==NULL)
		{
			printf("error");
			exit(-1);
		}
}
void init_node(struct node** p)
{
	creat_memory(p);
		(*p)->next=(*p);
		(*p)->prev=(*p);
}
void creat_head_chain(struct node* phead)
{
	int num_size;
	struct node *pnew=NULL;
	    for(num_size=0;num_size<10;num_size++)
		{
		init_node(&pnew);
		  pnew->num=num_size;

		  pnew->next = phead->next;
		  phead->next->prev = pnew;
		  phead->next = pnew;
		  pnew->prev = phead;
		}
}

void creat_end_chain(struct node* phead)
{
	int num_size;
	struct node *pnew=NULL;
	struct node* ptail = phead;
	    for(num_size=0;num_size<10;num_size++)
		{
			init_node(&pnew);
			pnew->num=num_size;

			ptail->next = pnew;
			pnew->prev = ptail;
			pnew->next = phead;
			phead->prev = pnew;
			 
			ptail = pnew;
		}
}

void show_chain(struct node* phead){
	struct node* cur;
	for(cur = phead; cur->next != phead; cur = cur->next){
		printf("%d\n", cur->next->num);
	}
}

void destroy_chain(struct node* phead){
	
	if(phead != NULL){
		struct node* cur = NULL;
		
		while(phead->next != phead){
			cur = phead->next;
			phead->next = cur->next;

			if(cur != NULL){
				printf("free [%d]\n", cur->num);
				free(cur);
			}
		}
		
		printf("free the head\n");
		free(phead);
	}
}

int main()
{
	struct node* p=NULL;
	init_node(&p);
	creat_head_chain(p);
	// creat_end_chain(p);
      show_chain(p);
	destroy_chain(p);

}
