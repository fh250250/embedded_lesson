#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	uid_t uid;
	gid_t gid;

	struct passwd* ret;
	struct group* ret_g;
	
	uid = getuid();
	gid = getgid();

	ret = getpwuid(uid);
	ret_g = getgrgid(gid);

	printf("%s\n", ret->pw_name);
	printf("%s\n", ret_g->gr_name);

	return 0;
}