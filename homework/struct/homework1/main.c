#include "main.h"

void add_student(SingleChain* single_chain);
int dump(SingleChain* single_chain, const char* path);
void show(SingleChain* single_chain);
Student* find_by_id(SingleChain* single_chain, size_t id);





int main(int argc, char const *argv[])
{
	SingleChain* single_chain = newSingleChain();

	add_student(single_chain);

	if(!dump(single_chain, "dump.txt")){
		printf("保存到硬盘失败\n");
	}

	show(single_chain);

	Student* student = find_by_id(single_chain, 4);
	if(student == NULL){
		printf("未找到\n");
	}else{
		printStudent(student);
	}



	delSingleChain(&single_chain);

	return 0;
}





void add_student(SingleChain* single_chain){
	size_t ids[] = {1, 2, 3, 4, 5};
	size_t ages[] = {22, 21, 22, 24, 23};
	char sexs[] = {'F', 'M', 'M', 'F', 'F'};
	char* names[] = {"galina", "alex", "jack", "fred", "bruce"};

	size_t i;
	Node* node;
	for(i = 0; i < 5; i++){
		node = newNode();
		setStudent(node->student, ids[i], ages[i], sexs[i], names[i]);
		push(single_chain, node);
	}
}

int dump(SingleChain* single_chain, const char* path){

	char buff[1024] = {0};
	Node* cur = single_chain->head;

	FILE* file = fopen(path, "w");
	if(file == NULL){
		printf("open %s failure\n", path);
		return 0;
	}

#if DEBUG == 1
	printf("开始向磁盘写入\n");
#endif

	while(cur->next != NULL){
		sprintf(buff, "id: %lu, age: %lu, sex: %c, name: %s\n",
			cur->next->student->id,
			cur->next->student->age,
			cur->next->student->sex,
			cur->next->student->name);

		fputs(buff, file);

		cur = cur->next;
	}

	fclose(file);

#if DEBUG == 1
	printf("写入完成, 保存至文件 %s\n", path);
#endif


	return 1;
}

void show(SingleChain* single_chain){
	Node* cur = single_chain->head;

	while(cur->next != NULL){
		printStudent(cur->next->student);

		cur = cur->next;
	}
}

Student* find_by_id(SingleChain* single_chain, size_t id){
	Node* cur = single_chain->head;

	while(cur->next != NULL){
		if(cur->next->student->id == id){
			return cur->next->student;
		}

		cur = cur->next;
	}

	return NULL;
}
