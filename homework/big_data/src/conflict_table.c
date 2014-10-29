#include "../include/conflict_table.h"


conflict_node* create_conflict_node(const char* word){
	char* pword = malloc(sizeof(char) * (strlen(word) + 1));

	if(pword == NULL){
		perror("allocate mem failure\n");
		exit(-1);
	}

	strcpy(pword, word);

	conflict_node* node = malloc(sizeof(conflict_node));
	if(node == NULL){
		perror("allocate mem failure\n");
		exit(-1);		
	}

	node->word = pword;
	node->index = NULL;
	node->next = NULL;

	return node;
}

