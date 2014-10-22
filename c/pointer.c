#include <stdio.h>

int main(){

#if 0
	int *p;  // p 是指向整形变量的指针变量
			 // 指针   <------->   地址
			 // 野指针 随机值

	int* p1, p2;  // p1 is a pointer, p2 is not

	void* p3;		// ISO c89 c99 不支持void* 类型的指针变量自增

	int num;
	p = &num;	// 关联
#endif

#if 0
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int* p;
	p = arr;
	// p = (int*)((int)(arr)+1);

	p = (int*)(&arr+1);
	printf("%d\n", p[-1]);
	printf("%d\n", *(p-2));
#endif

#if 1
	printf("%ld\n", sizeof( char(*)[5] ));
	printf("%ld\n", sizeof( char* [5] ));
#endif

#if 0
	char arr[10];
	printf("arr     = %u\n", arr);
	printf("arr+1   = %u\n", arr+1);
	printf("&arr+1  = %u\n", &arr+1);
#endif

}

