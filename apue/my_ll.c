#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void print_mode(mode_t mode);
void print_uname(uid_t uid);
void print_gname(gid_t gid);
void print_time(time_t mtime);


int main(int argc, char const *argv[])
{

	struct stat stat_buff;

	if(stat(argv[1], &stat_buff) < 0){
		perror("stat");
		exit(1);
	}

	print_mode(stat_buff.st_mode);
	printf(" ");
	printf("%lu ", stat_buff.st_nlink);
	print_uname(stat_buff.st_uid);
	printf(" ");
	print_gname(stat_buff.st_gid);
	printf(" ");

	printf("%lu ", stat_buff.st_size);

	print_time(stat_buff.st_mtime);
	printf("%s\n", argv[1]);


	return 0;
}



void print_mode(mode_t mode){
	if(S_ISDIR(mode))
		printf("d");
	else if(S_ISCHR(mode))
		printf("c");
	else if(S_ISBLK(mode))
		printf("b");
	else if(S_ISREG(mode))
		printf("-");
	else if(S_ISFIFO(mode))
		printf("p");
	else if(S_ISLNK(mode))
		printf("l");
	else if(S_ISSOCK(mode))
		printf("s");
	

	printf("%s", mode & S_IRUSR ? "r" : "-");
	printf("%s", mode & S_IWUSR ? "w" : "-");
	printf("%s", mode & S_IXUSR ? "x" : "-");

	printf("%s", mode & S_IRGRP ? "r" : "-");
	printf("%s", mode & S_IWGRP ? "w" : "-");
	printf("%s", mode & S_IXGRP ? "x" : "-");

	printf("%s", mode & S_IROTH ? "r" : "-");
	printf("%s", mode & S_IWOTH ? "w" : "-");
	printf("%s", mode & S_IXOTH ? "x" : "-");
}


void print_uname(uid_t uid){
	printf("%s", getpwuid(uid)->pw_name);
}



void print_gname(gid_t gid){
	printf("%s", getgrgid(gid)->gr_name);
}


void print_time(time_t mtime){
	struct tm* ptm;

	ptm = gmtime(&mtime);

	printf("%d ", ptm->tm_mon + 1);
	printf("%d ", ptm->tm_mday);
	printf("%d:", (ptm->tm_hour + 8) % 24);
	printf("%d ", ptm->tm_min);
	
	// printf("%s", asctime(ptm));
}


