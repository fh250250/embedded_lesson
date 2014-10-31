#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H


#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "../include/conflict_table.h"
#include "../include/misc.h"




/**
 * 控制台界面运行
 */
void console_run(int argc, char const *argv[]);


/**
 * 判断字符串是否是合法目录
 * @param  dirname 目录名
 * @return         y/n
 */
int is_dir_valid(const char* dirname);



/**
 * 将目录名改为已/结尾的
 * @param dirname 目录名
 */
void fix_dirname(char* dirname);


/**
 * 查找单词
 * @param hash_table hash表
 */
void loop_for_search(conflict_node** hash_table);



/**
 * 打印结果
 * @param result 冲突节点
 */
void print_result(conflict_node* result);


#endif