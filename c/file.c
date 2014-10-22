#include "apue.h"

int main(int argc, char const *argv[])
{
	char arr[100] = "abcd";
	char arr_1[100];
	FILE* p;
	p = fopen("a.txt", "w+");

	fwrite(arr, sizeof(char), sizeof(arr), p);

	rewind(p);

	fread(arr_1, sizeof(char), sizeof(arr_1), p);

	printf("%s\n", arr_1);
	
	return 0;
}