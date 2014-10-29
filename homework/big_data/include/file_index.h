#ifndef FILE_INDEX_H
#define FILE_INDEX_H


#include <stdlib.h>




typedef struct index_node
{
	char* file_name;	// 文件名
	unsigned int lines;	// 行号
	struct index_node* next;
} index_node;



/**
 * 创建一个索引节点
 * @param  file_name 文件名
 * @param  lines     行号
 * @return           索引节点指针
 */
index_node* create_index_node(const char* file_name, unsigned int lines);


#endif