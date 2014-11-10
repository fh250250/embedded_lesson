#include <stdio.h>
#include <unistd.h>



int main(int argc, char* argv[]){

	// execl("./exe", "./exe", NULL);

	execv("/bin/cat", argv);

	return 0;
}
