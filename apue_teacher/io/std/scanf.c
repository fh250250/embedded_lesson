#include <stdio.h>

int main(void)
{
	int a;
	char buf[256];
	FILE *fp;	

	fp = fopen("t.txt", "r");
	fscanf(fp, "%d", &a);
	printf("a = %d\n",a);

//	fscanf(stdin, "%d", &a);



//	scanf("%d", &a);
	
//	sscanf("123", "%d", &a);
//	sscanf("abcd", "%s", buf);
	


//	printf("buf = %s\n", buf);

	return 0;
}

