#include <stdio.h>


int main(int argc, char* argv[]){
	if(argc != 2){
		printf("usage: %s <integer>\n", argv[0]);
		return 1;
	}

	int arr[7] = {-1, 7, 22, 40, 43, 57};

	int i;
	for(i = 0; i < sizeof(arr) - 1; i++)
		printf("%d ", arr[i]);
	printf("\n");

	insert_to_arrary(arr, sizeof(arr), atoi(argv[1]));

	for(i = 0; i < sizeof(arr); i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
