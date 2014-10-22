#include "apue.h"

typedef struct{
	char* name;
} Person;

void setName(Person* person, const char* name){
	person->name = (char*)malloc((strlen(name)+1) * sizeof(char));
	if(person->name == NULL){
		exit(-1);
	}

	strcpy(person->name, name);
}

int main(int argc, char const *argv[])
{
	Person alex;
	setName(&alex, "alex");

	printf("My name is %s.\n", alex.name);

	return 0;
}