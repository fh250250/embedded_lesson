#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	int count = 0;

	if(*n == 0)
		*lineptr = NULL;

	while(1){
		ch = fgetc(stream);
		if(ch == EOF)
			return -1;
#if 0
		if(*n > count){
			(*lineptr)[count] = ch;
			count++;
		}else{
			*lineptr = realloc(*lineptr, *n + 120);
			*n = *n +120;
			
			(*lineptr)[count] = ch;
			count++;
		}
#else
		if(*n <= count){
			*lineptr = realloc(*lineptr, *n + 120);
			*n = *n +120;
		}
		(*lineptr)[count] = ch;
		count++;
#endif


		if(ch == '\n'){
			break;
		}

	}
	(*lineptr)[count] = '\0';

	if(count == 0)
		return -1;

	return count;

}


int main(void)
{
	char *lineptr;
	size_t n = 0;
	ssize_t ret;	
	
	while(1){
	
		ret = my_getline(&lineptr, &n, stdin);
	
		printf("ret = %d\n", ret);

		printf("lineptr = %s\n", lineptr);

		printf("n = %d\n\n\n",n);

	}
	return 0;
}

