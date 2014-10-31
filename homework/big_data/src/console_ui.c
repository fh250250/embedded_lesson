#include "../include/console_ui.h"



void console_run(int argc, char const *argv[]){

	if(argc != 2){
		printf("usage: %s <dirname>\n", argv[0]);
		return;
	}

	char buff[128] = {0};
	strcpy(buff, argv[1]);

	if(!is_dir_valid(buff)){
		printf("无此目录\n");
		return;
	}

	fix_dirname(buff);


	// buff 里现在是有效合法的目录名
	conflict_node** hash_table = build_to_ram(buff);

	loop_for_search(hash_table);
}


int is_dir_valid(const char* dirname){
	DIR* dir = opendir(dirname);

	if(dir){
		closedir(dir);

		return 1;
	}

	return 0;
}



void fix_dirname(char* dirname){
	char* p;

	for(p = dirname; *p; p++);

	if(*(p-1) != '/'){
		*p = '/';
		*(p+1) = 0;
	}
}



void loop_for_search(conflict_node** hash_table){


	char buff[128] = {0};

	for(;;){
		printf("输入要搜索的单词> ");
		scanf("%s", buff);
		getchar();

		print_result(find_word(buff, hash_table));

		printf("Go on?[y/n]");
		scanf("%c", buff);

		if(*buff == 'n'){
			return;
		}
	}

}


void print_result(conflict_node* result){
	if(result == NULL){
		printf("没有找到结果\n");
	}else {
		index_node* cur = result->index;

		while(cur){
			printf("\"%s\" : %u\n", cur->file_name, cur->lines);

			cur = cur->next;
		}
	}
}
