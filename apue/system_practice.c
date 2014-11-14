#include <stdio.h>
#include <stdlib.h>


int main(){

	char cmd[] = "for file in *;do cp $file /tmp/pipe/my_$file;done";
	
	system(cmd);

	return 0;
}

