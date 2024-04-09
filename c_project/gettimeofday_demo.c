#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(void)
{
	struct timeval tval;
	int ret;

	ret = gettimeofday(&tval, NULL);

	printf("%ld sec  %ld msec\n", tval.tv_sec, tval.tv_usec);

	exit(0);
}
