#include <stdio.h>
#include <time.h>

void swap(int* arr, int low, int high){
	int tmp = arr[high];
	arr[high] = arr[low];
	arr[low] = tmp;
}

int sort(int* arr, int low, int high){
	int num = arr[low];
	while(low < high){
		while(num < arr[high]&&low<high)
			high--;
		if(low < high){
			swap(arr, low, high);
			low++;
		}

		while(num > arr[low]&&low<high)
			low++;
		if(low < high){
			swap(arr, low, high);
			high--;
		}

	}

	return low;
}

void quick_sort(int* arr, int low, int high){
	int ret = sort(arr, low, high);
	if(low < ret-1){
		quick_sort(arr, low, ret-1);
	}
	if(ret+1<high){
		quick_sort(arr, ret+1, high);
	}
}

void quickSort(int* arr, int low, int high){
	int x = arr[low];
	int left = low;
	int right = high;

	while(left < right){
		while(x < arr[right] && left < right)
			right--;
		if(left < right){
			arr[left] = arr[right];
			left++;
		}

		while(x > arr[left] && left < right)
			left++;
		if(left < right){
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = x;

	if(low < left - 1)
		quickSort(arr, low, left - 1);
	if(high > left + 1)
		quickSort(arr, left + 1, high);
}


int main(){
	int num, arr[10] = {55,22,3,43,15,46,7,68,19,10};

	clock_t t1 = clock();

	quickSort(arr, 0, 9);

	clock_t t2 = clock();


	int i;
	for(i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("time: %lf\n", (double)(t2-t1)/CLOCKS_PER_SEC);

}

