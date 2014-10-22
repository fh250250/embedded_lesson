// hash存储

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 32

struct node_t
{
	int data;
	struct node_t* next;
};
typedef struct node_t node_t;



node_t** init_hash_table();

void rand_store(node_t** table, size_t n, size_t max);


void show_table(node_t** table);



int main(int argc, char const *argv[])
{
	node_t** hash_table = init_hash_table();

	size_t n, max;

	printf("Input how much data do U want> ");
	scanf("%lu", &n);
	printf("and the Max limit> ");
	scanf("%lu", &max);

	rand_store(hash_table, n, max);

	show_table(hash_table);
	
	
	

	return 0;
}

node_t** init_hash_table(){
	node_t** table = NULL;
	table = malloc(N * sizeof(node_t*));

	if(table == NULL){
		exit(-1);
	}

	memset(table, 0, N * sizeof(node_t*));

	return table;
}

// 产生随机数据填充hash表
void rand_store(node_t** table, size_t n, size_t max){
	size_t i;
	int x;
	size_t index;
	node_t* node;
	srand((unsigned int)time(0));

	for(i = 0; i < n; i++){
		x = rand() % max;
		index = (x >> 1) & (N - 1);

		node = malloc(sizeof(node));
		if(node == NULL){
			exit(-1);
		}

		node->data = x;

		if(*(table + index) == NULL){
			*(table + index) = node;
			node->next = NULL;
		}else {
			node->next = *(table + index);
			*(table + index) = node;
		}

	}
}

void show_table(node_t** table){
	size_t i;
	node_t* cur;

	printf("--------------------------------------------------\n");

	for(i = 0; i < N; i++){
		printf("[%3lu]: ", i);

		if(*(table + i) != NULL){
			cur = *(table + i);
			while(cur != NULL){
				printf("%-5d", cur->data);

				cur = cur->next;
			}
		}
		printf("\n");
	}

	printf("--------------------------------------------------\n");

}
