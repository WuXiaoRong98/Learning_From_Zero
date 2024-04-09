#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv)
{
	printf("max process %ld\n", sysconf(_SC_CHILD_MAX));
	printf("tick %ld\n", sysconf(_SC_CLK_TCK));
	printf("pagesize %ld\n", sysconf(_SC_PAGESIZE));

	exit(0);
}
