#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

typedef struct
{
	size_t len;
	node* head;
} list;

// 新建链表
list* newList();

// 新建节点
node* newNode();

// 插入节点
int insert(list* l, size_t index, int data);

// 删除节点
int del(list* l, size_t index);

// 获取元素
node* get(list* l, size_t index);

// 删除链表
void distory(list* l);

// 打印整个链表
void show(list* l);

#endif