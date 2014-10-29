#ifndef MISC_H
#define MISC_H


#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "../include/hash_table.h"
#include "../include/dname_stack.h"


#define MAX_LINE_LEN 1024
#define DELIM " ,.?!:;\"'<>()[]{}\n\t@#$^&*-=+/|"


/**
 * 扫描整个目录,对每个文件进行分词处理,建立hash表
 * @param  dirname 目录名
 * @return         hash表头指针
 */
conflict_node** build(const char* dirname);


/**
 * 递归遍历目录,并构建hash表
 * @param dirname    目录名
 * @param hash_table hash表头指针
 */
void walk_tree(const char* dirname, conflict_node** hash_table);


/**
 * 分析文件,构建hash表
 * @param dname      文件名
 * @param hash_table hash表
 */
void analyze_file(const char* file_name, conflict_node** hash_table);



/**
 * 分析一行数据,找到单词,向hash表中添加
 * @param line_buff  行缓冲区
 * @param lines      行号
 * @param file_name  文件名
 * @param hash_table hash表
 */
void deal_with_line(char* line_buff, unsigned int lines, 
					const char* file_name, conflict_node** hash_table);



/**
 * 将单词加入hash表
 * @param word       单词
 * @param hash_table hash表
 * @param file_name  文件名
 * @param lines      行号
 */
void add_word_to_hash_table(const char* word, conflict_node** hash_table, 
							const char* file_name, 
							unsigned int lines);



/**
 * 对字符串做hash运算
 * @param  word 单词
 * @return      hash值
 */
unsigned int hash_func(const char* word);


#endif