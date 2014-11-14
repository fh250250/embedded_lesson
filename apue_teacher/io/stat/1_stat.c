#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int ret;
	struct stat buf;
	mode_t mode;
	
	ret = stat(argv[1], &buf);
	if(ret < 0){
		perror("stat");
		exit(1);
	}

	mode = buf.st_mode;

	if(S_ISDIR(mode)){
		printf("d");
	}else if(S_ISCHR(mode)){
		printf("c");
	}else if(S_ISBLK(mode)){
		printf("b");
	}else if(S_ISREG(mode)){
		printf("-");
	}else if(S_ISFIFO(mode)){
		printf("p");
	}else if(S_ISLNK(mode)){
		printf("l");
	}else if(S_ISSOCK(mode)){
		printf("s");
	}else{
	}
	char b[10]={"rwxrwxrwx"};
	int i;
	for(i = 0; i < 9; i++){
		if(mode & (1<<(8-i))){
			printf("%c",b[i]);
		}else{
			printf("-");
		}
	}
	printf(". ");
	printf("%d ",buf.st_nlink);
	struct passwd *ps;
	ps = getpwuid(buf.st_uid);
	printf("%s ", ps->pw_name);
	struct group *gr;
	gr = getgrgid(buf.st_gid);	
	printf("%s ",gr->gr_name);
	printf("%d ",buf.st_size);
//	printf("%d\n",buf.st_mtime);
	struct tm *tm;
	tm = gmtime(&buf.st_mtime);
	printf("%d月  ",(tm->tm_mon+1)%12);
	printf("%d ", tm->tm_mday);
	printf("%d:%d ",(tm->tm_hour+8)%24, tm->tm_min);

	printf("%s\n",argv[1]);

	return 0;
}
