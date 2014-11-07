#include <stdio.h>


// extern char** environ;



int main(int argc, char* argv[], char* envp[]){

//	int i;

//	for(i = 0; environ[i]; i++)
//		printf("%s\n", environ[i]);

	char** p;
	for(p = envp; *p; p++)
		printf("%s\n", *p);

	return 0;
}
