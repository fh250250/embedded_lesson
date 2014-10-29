#include "../include/misc.h"



conflict_node** build(const char* dirname){

	conflict_node** hash_table = create_hash_table();

	// 遍历目录 并构建
	walk_tree(dirname, hash_table);

	return hash_table;
}

void walk_tree(const char* dirname, conflict_node** hash_table){

	// 初始化栈,并压入第一个目录
	dname_node* stack = initStack();
	push_stack(stack, dirname);


	DIR* dir;
	struct dirent* ptr;
	char* dname;
	char* name_buff;

	while(!is_stack_empty(stack)){
		// 从栈里取一个
		dname = pop_stack(stack);


		dir = opendir(dname);

		while((ptr = readdir(dir)) != NULL){

			// 构造名字缓冲区
			name_buff = malloc(sizeof(char) * (strlen(dname) + strlen(ptr->d_name) + 2));
			if(name_buff == NULL){
				perror("allocate mem error\n");
				exit(-1);
			}

			// 构造字符串
			strcpy(name_buff, dname);
			strcat(name_buff, ptr->d_name);
			

			if(ptr->d_type == DT_DIR){	// 把子目录压栈
				if(strcmp(ptr->d_name, ".") && strcmp(ptr->d_name, "..")){
					strcat(name_buff, "/");

					push_stack(stack, name_buff);
				}
			}else {	// 处理文件
				analyze_file(name_buff, hash_table);
			}


			// 释放掉目录名缓冲区
			if(name_buff){
				free(name_buff);
			}

		}

		closedir(dir);

		// 释放目录名占的空间
		if(dname){
			free(dname);
		}

	}

	// 释放掉空栈
	if(stack){
		free(stack);
	}
}



void analyze_file(const char* file_name, conflict_node** hash_table){
	FILE* file = fopen(file_name, "r");
	char* line_buff;
	unsigned int lines;

	if(!file){
		printf("读取文件\"%s\"失败\n", file_name);
		return;
	}

	// 行缓冲
	line_buff = malloc(sizeof(char) * MAX_LINE_LEN);
	if(!line_buff){
		perror("allocate mem failure\n");
		exit(-1);
	}


	// 逐行分析
	for(lines = 1; fgets(line_buff, MAX_LINE_LEN, file); lines++){
		deal_with_line(line_buff, lines, file_name, hash_table);
	}


	if(line_buff){
		free(line_buff);
	}
	fclose(file);
}


void deal_with_line(char* line_buff, unsigned int lines, 
					const char* file_name, conflict_node** hash_table){
	char* word;
	char* delim = DELIM;	// 分隔符
	char* p;

	for(p = line_buff; ; p = NULL){
		word = strtok(p, delim);

		if(!word) break;

		add_word_to_hash_table(word, hash_table, file_name, lines);
	}
}


void add_word_to_hash_table(const char* word, conflict_node** hash_table, 
							const char* file_name, 
							unsigned int lines){

	// hash掉单词,并找到对应的槽
	conflict_node* conflict_chain = *(hash_table + hash_func(word));


	conflict_node* node = NULL;
	conflict_node* cur = NULL;
	index_node* pIndex = NULL;


	// printf("\"%s\":%u:%s\n", file_name, lines, word);




	if(conflict_chain == NULL){ // 当前槽还没有冲突

		// 冲突节点
		node  = create_conflict_node(word);
		pIndex = create_index_node(file_name, lines);

		node->index = pIndex;

		conflict_chain = node;


	}else {		// 当前槽有冲突
		cur = conflict_chain;

		while(cur != NULL){
			if(strcmp(cur->word, word) == 0){
				// 只用再追加索引
				// 到索引链的头部
				pIndex = create_index_node(file_name, lines);
				pIndex->next = cur->index;
				cur->index = pIndex;
				
				return;
			}

			cur = cur->next;
		}

		// 在头部插入一个新的
		node  = create_conflict_node(word);
		pIndex = create_index_node(file_name, lines);

		node->index = pIndex;
		node->next = conflict_chain;
		conflict_chain = node;
	}
}


unsigned int hash_func(const char* word){
	unsigned int sum = 0;
	const char* p;

	for(p = word; *p; p++){
		sum += *p;
	}

	return sum % HASH_TABLE_LEN;
}

