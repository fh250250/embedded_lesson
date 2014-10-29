#ifndef CONFLICT_TABLE_H
#define CONFLICT_TABLE_H


#include <stdlib.h>
#include <string.h>
#include "../include/file_index.h"



// 冲突链表为单链表
typedef struct conflict_node
{
	char* word;						// 单词首地址
	index_node* index;				// 索引单链表
	struct conflict_node* next;
} conflict_node;


/**
 * 创建一个冲突节点
 * @param  word 单词
 * @return      冲突节点指针
 */
conflict_node* create_conflict_node(const char* word);


#endif
