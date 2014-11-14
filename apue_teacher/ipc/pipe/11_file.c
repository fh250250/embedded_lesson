#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char *ret;
	char buf[256];
	char buf_tmp[256];	
	fp = popen("ls", "r");
	if(fp == NULL){
		perror("popen");
		exit(1);
	}
	while(1){
		ret = fgets(buf, sizeof(buf), fp);
		if(ret == NULL)
			break;
		buf[strlen(buf)-1] = '\0';
		sprintf(buf_tmp,"cp %s /tmp/pipe/%s%s",buf,"my_",buf);
		printf("%s\n", buf_tmp);
		system(buf_tmp);	
	}


	return 0;
}



