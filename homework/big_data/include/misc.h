#ifndef MISC_H
#define MISC_H


#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "../include/hash_table.h"
#include "../include/dname_stack.h"




// 额外数据
typedef struct Extra {
	void* data;
	void (*func)(const char* word,
				 const char* file_name, 
				 unsigned int lines, 
				 void* data);
} Extra;







#define MAX_LINE_LEN 1024
#define DELIM " ,.?!:;\"'<>()[]{}\n\t@#$^&*-=+/|"


/**
 * 扫描整个目录,对每个文件进行分词处理,输出到文件
 * @param  dirname 目录名
 */
void build_to_disk(const char* dirname);
void build_to_disk_call_back(const char* word,
				 			const char* file_name, 
				 			unsigned int lines, 
				 			void* data);




/**
 * 在内存中构建
 * @param  dirname 目录名
 * @return         hash表
 */
conflict_node** build_to_ram(const char* dirname);
void build_to_ram_call_back(const char* word,
				 			const char* file_name, 
				 			unsigned int lines, 
				 			void* data);




/**
 * 递归遍历目录
 * @param dirname    目录名
 * @param out_file   输出文件
 */
void walk_tree(const char* dirname, Extra* extra);


/**
 * 分析文件
 * @param file_name 文件名
 * @param out_file  输出文件
 */
void analyze_file(const char* file_name, Extra* extra);




/**
 * 分析一行数据,找到单词
 * @param line_buff  行缓冲区
 * @param lines      行号
 * @param file_name  文件名
 * @param out_file   输出文件
 */
void deal_with_line(char* line_buff, unsigned int lines, 
					const char* file_name, Extra* extra);



/**
 * 对字符串做hash运算
 * @param  word 单词
 * @return      hash值
 */
unsigned int hash_func(const char* word);



/**
 * 在hash表中查找单词
 * @param  word       单词
 * @param  hash_table hash表
 * @return            冲突节点
 */
conflict_node* find_word(const char* word, conflict_node** hash_table);


#endif