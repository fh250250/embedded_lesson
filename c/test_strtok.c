#include <stdio.h>
#include <string.h>

int main(){

	char s[] = "? s ?d ";

	char* delim = " ?";
	char* p;
	char* q;

	for(p = s; ; p = NULL){
		
		q = strtok(p, delim);

		if(!q) break;

		printf("%s\n", q);
	}

	printf("---------------\n%s\n", s);

	return 0;
}
