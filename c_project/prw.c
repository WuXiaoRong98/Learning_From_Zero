#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned char buffer[100];
	int fd;
	int ret;

	fd = open("./test_file", O_RDWR);
	if (fd < 0) {
		perror("open failed");
		exit(-1);
	}

	ret = pread(fd, buffer, sizeof(buffer), 1024);
	if (ret == -1) {
		perror("pread error");
		close(fd);
		exit(-2);
	}

	ret = lseek(fd, 0, SEEK_CUR);
	if (ret == -1) {
		perror("lseek error");
		close(fd);
		exit(-3);
	}

	printf("current offset : %d\n", ret);

	close(fd);

	exit(0);
}
