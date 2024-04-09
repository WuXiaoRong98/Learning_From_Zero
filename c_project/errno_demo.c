#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	printf("errno = %d\n", errno);

	int fd = open("./test.txt", O_CREAT | O_EXCL, 0777);
	if (fd < 0) {
		fprintf(stderr, "open failed %s\n", strerror(errno));
		perror("open failed");
		//return -1;
		_exit(-1);
	}

	close(fd);

//	return 0;
	_Exit(0);
}
