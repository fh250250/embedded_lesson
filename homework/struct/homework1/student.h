#ifndef STUDENT_H
#define STUDENT_H

#include "main.h"


struct Student
{
	size_t id;
	size_t age;
	char   sex;
	char  name[100];
};
typedef struct Student Student;

// 新建一个学生
Student* newStudent();

// 销毁一个学生
void delStudent(Student** student);

// 设置学生信息
void setStudent(Student* student, size_t id, size_t age, char sex, const char* name);

// 打印一个学生的信息
void printStudent(Student* student);

#endif