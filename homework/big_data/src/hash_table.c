#include "../include/hash_table.h"

conflict_node** create_hash_table(){
	conflict_node** hash_table = NULL;

	hash_table = malloc(sizeof(conflict_node*) * HASH_TABLE_LEN);

	if(hash_table == NULL){
		perror("无足够内存创建hash表\n");

		exit(-1);
	}

	// 初始化hash表
	memset(hash_table, 0, sizeof(conflict_node*) * HASH_TABLE_LEN);

	return hash_table;
}


