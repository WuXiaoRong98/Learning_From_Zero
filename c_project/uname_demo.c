#include <sys/utsname.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct utsname ustn = {0};

	int ret = uname(&ustn);

	if (ret < 0) {
		return -1;
	}

	printf("operating sysname: %s\n", ustn.sysname);
	printf("version : %s\n", ustn.version);
	printf("nodename %s\n", ustn.nodename);

	return 0;
}
