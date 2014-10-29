#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/conflict_table.h"



#define HASH_TABLE_LEN 1024


/**
 * 创建一个hash表,存储的是冲突表的指针,数组形式的
 * @return 冲突表首地址
 */
conflict_node** create_hash_table();



#endif
