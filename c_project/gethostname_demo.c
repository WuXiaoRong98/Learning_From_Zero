#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char hostname[100];

	int ret = gethostname(hostname, sizeof(hostname));

	printf("%s\n", hostname);

	return 0;
}
