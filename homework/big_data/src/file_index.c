#include "../include/file_index.h"


index_node* create_index_node(const char* file_name, unsigned int lines){

	index_node* pIndex = malloc(sizeof(index_node));
	if(pIndex == NULL){
		perror("allocate mem failure\n");
		exit(-1);
	}

	// 文件名
	char* fname = malloc(sizeof(char) * (strlen(file_name) + 1));
	if(fname == NULL){
		perror("allocate mem failure\n");
		exit(-1);
	}

	strcpy(fname, file_name);

	pIndex->file_name = fname;
	pIndex->lines = lines;
	pIndex->next = NULL;


	return pIndex;
}

