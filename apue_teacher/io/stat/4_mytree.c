#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int mytree(char *name, int level)
{
	DIR *d;
	int i;
	struct dirent *r;
	char buf[256];
	if(level == 0)
		printf("%s\n",name);
	d = opendir(name);
	if(d == NULL){
		return 0;
	}
	while(1){
		r = readdir(d);
		if(r == NULL)
			break;
		if(r->d_name[0] == '.')
			continue;
		for(i = 0; i < level+1; i++)
			printf("  ");
		printf("%s\n",r->d_name);
		sprintf(buf, "%s/%s",name,r->d_name);	
		mytree(buf, level+1);
	}
}

int main(int argc, char *argv[])
{
	char *tmp = argv[1];	

	if(tmp[strlen(tmp)-1] == '/')
		tmp[strlen(tmp)-1] = '\0';

	mytree(argv[1], 0);

	return 0;
}


