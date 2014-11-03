#include <stdio.h>
#include <stdlib.h>


ssize_t my_getline(char** lineptr, size_t* n, FILE* stream);



int main(int argc, char const *argv[])
{
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(argv[1], "r");
   if (fp == NULL)
       exit(EXIT_FAILURE);

   while ((read = my_getline(&line, &len, fp)) != -1) {
       // printf("Retrieved line of length %zu :\n", read);
       printf("%s", line);
   }

   free(line);
   exit(EXIT_SUCCESS);

}


ssize_t my_getline(char** lineptr, size_t* n, FILE* stream){

	if(feof(stream))
		return -1;


	long start = ftell(stream);
	long end;
	int ch;

	while(ch = fgetc(stream)){
		if(ch == '\n' || ch == EOF)
			break;
	}

	end = ftell(stream);
	fseek(stream, start-end, SEEK_CUR);

	if(*lineptr == NULL){
		*lineptr = malloc(sizeof(char) * (end - start + 1));
		if(*lineptr == NULL){
			perror("malloc()");
			exit(1);
		}

		*n = end - start + 1;
	}else {
		if(end - start > *n){
			*lineptr = realloc(*lineptr, (end - start + 1) * 2);
			if(*lineptr == NULL){
				perror("realloc()");
				exit(1);
			}

			*n = (end - start + 1) * 2;
		}
	}

	char* p = *lineptr;
	while(ch = fgetc(stream)){
		*p = ch;

		if(ch == '\n'){
			*(p+1) = 0;
			break;
		}

		if(ch == EOF){
			*p = 0;
			break;
		}

		p++;
	}


	return end - start + 1;

}
