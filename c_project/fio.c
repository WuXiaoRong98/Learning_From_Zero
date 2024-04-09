#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char buffer[100];
	FILE *fp = fopen("./test.txt", "r");
	if (NULL ==  fp) {
		exit(-1);
	}

	fread(buffer, 100, 1, fp);
	printf("%s\n", buffer);
	fclose(fp);
	return 0;
}
