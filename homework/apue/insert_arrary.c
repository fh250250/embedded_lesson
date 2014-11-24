
void insert_to_arrary(int* arr, int size, int num){
	int i;
	for(i = size - 2; i >= 0 && num < arr[i]; i--){
		arr[i + 1] = arr[i];
	}

	arr[i + 1] = num;
}

