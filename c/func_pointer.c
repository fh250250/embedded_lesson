#include "apue.h"

int add(int* a, int b){
	return 3+1;
}

int sub(int* a, int b){
	return 3-1;
}

int main(){
	typedef int(*fun)(int*, int);

	fun fun_arr[2] = {add, sub};

	

	return 0;
}
