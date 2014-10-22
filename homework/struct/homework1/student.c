#include "main.h"

Student* newStudent(){
	Student* student = NULL;

	student = malloc(sizeof(Student));
	if(student == NULL){
#if DEBUG == 1
		printf("内存不足\n");
#endif
		exit(-1);
	}

#if DEBUG == 1
	printf("Student 分配内存成功\n");
#endif

	// 初始化
	student->id   = 0;
	student->age  = 0;
	student->sex  = 'M'; // 男
	memset(student->name, 0, sizeof(student->name));

	return student;
}

void delStudent(Student** student){
	if(*student != NULL){
		free(*student);

#if DEBUG == 1
		printf("Student 已释放\n");
#endif

		*student = NULL;
	}
}

void setStudent(Student* student, size_t id, size_t age, char sex, const char* name){
	student->id = id;
	student->age = age;
	student->sex = sex;
	strcpy(student->name, name);
#if DEBUG == 1
	printf("student --> id:%lu, age:%lu, sex:%c, name:%s\n",
		student->id, student->age, student->sex, student->name);
#endif
}

void printStudent(Student* student){
	printf("id: %lu, age: %lu, sex: %c, name: %s\n",
		student->id,
		student->age,
		student->sex,
		student->name);
}
