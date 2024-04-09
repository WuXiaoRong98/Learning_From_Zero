#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	//int fd = open("./test.txt", O_CREAT | O_EXCL, 0777);
	char buffer[512] = {0};
	int fd = open("./test.txt", O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "open failed\n");
		return -1;
	}

	int rc = read(fd, buffer, sizeof(buffer));
	buffer[rc - 1] = '\0';

	printf("read buffer[%d]: %s\n", rc, buffer);

	close(fd);

	return 0;

}
