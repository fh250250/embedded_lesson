#include "../include/misc.h"



conflict_node** build_to_ram(const char* dirname){
	conflict_node** hash_table = create_hash_table();

	Extra extra;
	extra.data = hash_table;
	extra.func = build_to_ram_call_back;

	walk_tree(dirname, &extra);

	return hash_table;
}


void build_to_ram_call_back(const char* word,
				 			const char* file_name, 
				 			unsigned int lines, 
				 			void* data){
	conflict_node** hash_table = (conflict_node**)data;

	unsigned int slot = hash_func(word);
	conflict_node* node = NULL;
	conflict_node* cur = NULL;
	index_node* pIndex = NULL;


	if(*(hash_table + slot) == NULL){	// 当前槽还没有冲突

		node = create_conflict_node(word);
		pIndex = create_index_node(file_name, lines);

		node->index = pIndex;

		*(hash_table + slot) = node;

	}else {		// 当前槽有冲突

		cur = *(hash_table + slot);

		while(cur){
			if(strcmp(cur->word, word) == 0){ // 只用再添加索引
				pIndex = create_index_node(file_name, lines);

				pIndex->next = cur->index;
				cur->index = pIndex;

				return;
			}

			cur = cur->next;
		}

		// 在头部添加
		node = create_conflict_node(word);
		pIndex = create_index_node(file_name, lines);

		node->index = pIndex;

		node->next = *(hash_table + slot);
		*(hash_table + slot) = node;
	}
}





void build_to_disk(const char* dirname){

	char* name_buff = malloc(sizeof(char) * (strlen(dirname) + strlen("sym.tags") + 1));
	if(name_buff == NULL){
		perror("allocate mem failure\n");
		exit(-1);
	}

	strcpy(name_buff, dirname);
	strcat(name_buff, "sym.tags");

	FILE* out_file = fopen(name_buff, "w");
	if(!out_file){
		printf("打开文件\"%s\"失败\n", name_buff);
		return;
	}

	Extra extra;
	extra.data = out_file;
	extra.func = build_to_disk_call_back;

	// 遍历目录 并构建
	walk_tree(dirname, &extra);



	if(name_buff){
		free(name_buff);
	}

	fclose(out_file);
}



void build_to_disk_call_back(const char* word,
				 			const char* file_name, 
				 			unsigned int lines, 
				 			void* data){
	fprintf((FILE*)data, "%s:%u:%s:%u\n", 
		file_name, lines, word, hash_func(word));
}




void walk_tree(const char* dirname, Extra* extra){

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
				if(strcmp(ptr->d_name, "sym.tags"))
					analyze_file(name_buff, extra);
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



void analyze_file(const char* file_name, Extra* extra){
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
		deal_with_line(line_buff, lines, file_name, extra);
	}


	if(line_buff){
		free(line_buff);
	}
	fclose(file);
}


void deal_with_line(char* line_buff, unsigned int lines, 
					const char* file_name, Extra* extra){
	char* word;
	char* delim = DELIM;	// 分隔符
	char* p;

	for(p = line_buff; ; p = NULL){
		word = strtok(p, delim);

		if(!word) break;

		// 调用自定义函数
		extra->func(word, file_name, lines, extra->data);
	}
}



unsigned int hash_func(const char* word){
	unsigned int sum = 0;
	const char* p;

	for(p = word; *p; p++){
		sum += *p;
	}

	return (sum * 100 + 300) % HASH_TABLE_LEN;
}



conflict_node* find_word(const char* word, conflict_node** hash_table){

	conflict_node* conflict_chain = *(hash_table + hash_func(word));
	conflict_node* cur = NULL;

	if(conflict_chain){
		cur = conflict_chain;

		while(cur != NULL){
			if(strcmp(cur->word, word) == 0){
				return cur;
			}

			cur = cur->next;
		}
	}

	return NULL;
}


