#include <stdio.h>
#include <stdlib.h>
#include "my_list.h"

int main(int argc, char* argv[]){
	
	list_t* plist = create_list();
	if(plist == NULL){
		printf("create list failure\n");
		exit(EXIT_FAILURE);
	}

	int i;
	for (i = 0; i < 5; i++) {
		if(insert_list(plist, i, 10-i)){
			printf("insert to the list failure\n");
			exit(EXIT_FAILURE);
		}
	}
	print_list(plist);

	insert_list(plist, 1, 100);
	
	print_list(plist);

	// plist = reverse_list(plist);

	// print_list(plist);

	sort_list(plist);

	print_list(plist);

	return 0;
}
