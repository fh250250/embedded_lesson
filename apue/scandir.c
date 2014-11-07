#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[]){
   struct dirent **namelist;
   int n;

   n = scandir(argv[1], &namelist, NULL, alphasort);
   if (n < 0)
       perror("scandir");
   else {
       while (n--) {
           printf("%s\n", namelist[n]->d_name);
           free(namelist[n]);
       }
       free(namelist);
   }
}
