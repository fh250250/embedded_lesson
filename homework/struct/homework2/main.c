#include "main.h"

void show(SingleChain* single_chain);
void dealWith(SingleChain* single_chain);
int cmp(const void* p1, const void* p2);

int main(int argc, char const *argv[])
{
	SingleChain* A = newSingleChain();
	char buff[100] = {0};

	printf("Input a String> ");
	scanf("%s", buff);

	char* ch = buff;
	Node* node;
	while(*ch != '\0'){
		node = newNode();
		node->ch = *ch;
		push(A, node);

		ch++;
	}

	SingleChain* B = newSingleChain();
	SingleChain* C = newSingleChain();

	Node* cur = A->head;
	while(cur->next != NULL){
		node = newNode();
		node->ch = cur->next->ch;

		if(islower(cur->next->ch)){
			push(B, node);
		}else if(isupper(cur->next->ch)){
			push(C, node);
		}

		cur = cur->next;
	}

	// 释放掉A
	delSingleChain(&A);

	dealWith(B);
	show(B);
	// dealWith(C);
	
	return 0;
}

void show(SingleChain* single_chain){
	Node* cur = single_chain->head;
	while(cur->next != NULL){
		printf("%c ", cur->next->ch);

		cur = cur->next;
	}
	printf("\n");
}

void dealWith(SingleChain* single_chain){

	char* sort_buff = NULL;
	sort_buff = malloc(single_chain->len * sizeof(char));
	
	if(sort_buff == NULL){
#if DEBUG == 1
		printf("内存不足\n");
#endif
		exit(-1);
	}

#if DEBUG == 1
	printf("分配排序缓冲区\n");
#endif

	// 拷贝到缓冲区
	Node* cur = single_chain->head;
	char* ch = sort_buff;
	while(cur->next != NULL){
		*ch = cur->next->ch;

		cur = cur->next;
		ch++;
	}

	qsort(sort_buff, single_chain->len, sizeof(char), cmp);

	// 拷回至链表
	cur = single_chain->head;
	ch = sort_buff;
	while(cur->next != NULL){
		cur->next->ch = *ch;
		cur = cur->next;
		ch++;
	}

	if(sort_buff != NULL){
		free(sort_buff);
#if DEBUG == 1
	printf("释放排序缓冲区\n");
#endif
	}


}

int cmp(const void* p1, const void* p2){
	return *(char*)p1 > *(char*)p2;
}
