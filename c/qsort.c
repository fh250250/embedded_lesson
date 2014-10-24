#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node_t {
	int num;
	struct node_t* next;
};
typedef struct node_t node_t;


node_t* initStack();
void push(node_t* head, int num);
int pop(node_t* head);
void show_stack(node_t* head);
char is_empty(node_t* head);
void quickSort(int* arr, int low, int high);
int sort(int* arr, int low, int high);



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

int sort(int* arr, int low, int high){
	int x = arr[low];

	while(low < high){
		while(x < arr[high] && low < high)
			high--;
		if(low < high){
			arr[low] = arr[high];
			low++;
		}

		while(x > arr[low] && low < high)
			low++;
		if(low < high){
			arr[high] = arr[low];
			high--;
		}
	}

	arr[low] = x;

	return low;
}


void quickSort(int* arr, int low, int high){

	node_t* stack = initStack();
	if(low < high){
		int mid = sort(arr, low, high);

		if(low < mid - 1){
			push(stack, low);
			push(stack, mid - 1);
		}

		// show_stack(stack);

		if(mid + 1 < high){
			push(stack, mid + 1);
			push(stack, high);
		}

		// show_stack(stack);


		while(!is_empty(stack)){
			int right = pop(stack);
			int left = pop(stack);

			mid = sort(arr, left, right);

			if(left < mid - 1){
				push(stack, left);
				push(stack, mid - 1);
			}

			if(mid + 1 < right){
				push(stack, mid + 1);
				push(stack, right);
			}

			// sleep(1);
			// show_stack(stack);
		}
	}

	
}



node_t* initStack(){
	node_t* head = NULL;

	head = malloc(sizeof(node_t));
	if(head == NULL){
		exit(-1);
	}

	head->num = 0;
	head->next = NULL;

	return head;
}

void push(node_t* head, int num){
	node_t* node = NULL;

	node = malloc(sizeof(node_t));
	if(node == NULL){
		exit(-1);
	}

	node->num = num;

	node->next = head->next;
	head->next = node;
}

int pop(node_t* head){
	if(is_empty(head)){	// stack empty
		return -1;
	}

	node_t* node;
	int num;

	node = head->next;
	head->next = node->next;
	num = node->num;

	if(node != NULL){
		free(node);
	}

	return num;
}


char is_empty(node_t* head){
	return head->next == NULL;
}

void show_stack(node_t* head){
	node_t* cur = head;

	while(cur->next != NULL){
		printf("%d ", cur->next->num);

		cur = cur->next;
	}
	printf("\n");
}
