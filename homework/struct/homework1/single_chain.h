#ifndef SINGLE_CHAIN_H
#define SINGLE_CHAIN_H

#include "main.h"


// 节点
struct Node
{
	Student* student;
	struct Node* next;
};
typedef struct Node Node;

// 带头单链表
struct SingleChain
{
	Node* head;		// 头节点
	size_t len;		// 链表长度
};
typedef struct SingleChain SingleChain;



// 新建一个节点
Node* newNode();

// 销毁一个节点
void delNode(Node** node);



// 创建一个带头单链表
SingleChain* newSingleChain();

// 销毁一个单链表
void delSingleChain(SingleChain** single_chain);



// 在头部增加一个节点
void push(SingleChain* single_chain, Node* node);

// 在头部删除一个节点
void pop(SingleChain* single_chain);



// 清空一个单链表
void empty(SingleChain* single_chain);

#endif