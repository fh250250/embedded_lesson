#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>

int cp_file(char *src_name, char *dest_name)
{
	int ret;
	int src, dest;
	char buf[256];

	src = open(src_name, O_RDONLY);
	if(src < 0){
		perror("1open()");
		exit(1);
	}
	
	dest = open(dest_name, O_WRONLY|O_CREAT, 0644);
	if(dest < 0){
		perror("2open()");
		exit(1);
	}
	
	while(1){
		ret = read(src, buf, sizeof(buf));
		if(ret == 0)
			break;
		write(dest, buf, ret);
	}

}


int cp_tree(char *src_name, char *dest_name)
{
	DIR *d;
	int ret;
	char src_buf[256];
	char dest_buf[256];
	struct dirent * r;

	d = opendir(src_name);
	if(d == NULL){
		cp_file(src_name, dest_name);
		return 0;
	}else{
		ret = mkdir(dest_name, 0755);
		if(ret < 0){
			perror("mkdir()");
			exit(1);
		}
	}
	
	while(1){
		r = readdir(d);
		if(r == NULL)
			break;
		if(r->d_name[0] == '.')
			continue;
		
		sprintf(src_buf, "%s/%s", src_name,r->d_name);
		sprintf(dest_buf, "%s/%s", dest_name,r->d_name);

		cp_tree(src_buf, dest_buf);
	}

}

int main(int argc, char *argv[])
{

	cp_tree(argv[1], argv[2]);


	return 0;
}







