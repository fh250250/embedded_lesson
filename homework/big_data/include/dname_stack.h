#ifndef DNAME_STACK_H
#define DNAME_STACK_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct dname_node
{
	char* dname;	// 目录名首地址
	struct dname_node* next;
} dname_node;


/**
 * 初始化
 * @return 头结点
 */
dname_node* initStack();


/**
 * 加入一个目录名
 * @param head 头结点
 * @param dname 目录名
 */
void push_stack(dname_node* head, const char* dname);


/**
 * 弹出一个目录名
 * @param  head 头结点
 * @return      目录名指针
 */
char* pop_stack(dname_node* head);


/**
 * 栈是否为空
 * @param  head 头节点
 * @return      0/1
 */
char is_stack_empty(dname_node* head);

#endif