#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int main(void)
{
	int uid,gid;
	struct passwd *ret;
	struct group *gr;

	uid = getuid();
	
	ret = getpwuid(uid);

	printf("%s\n", ret->pw_name);

	gid = getgid();

	gr = getgrgid(gid);
	printf("%s\n", gr->gr_name);

	return 0;
}
