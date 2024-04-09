#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	srand(time(NULL));

	printf("random number = %d\n", rand() % 100);
}
