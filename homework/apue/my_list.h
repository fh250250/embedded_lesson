#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define ERR_ARG 1
#define ERR_MALLOC 2


struct node {
	int data;
	struct node* next;
};
typedef struct node node_t;
typedef node_t list_t;

// 创建一个链表
// 成功返回头结点
// 失败返回NULL
list_t* create_list();

// 向链表中插入一个数
// where: 从０开始的索引位置
//　返回０表示成功
int insert_list(list_t* head, int where, int data);


void print_list(list_t* list);

/**
 * 逆序链表
 * @param  head 头节点
 * @return      逆序后的头结点,失败为NULL
 */
list_t* reverse_list(list_t* head);

#endif
