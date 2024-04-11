#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main()
{
    int i = 0;

    for (i = 0; NULL != environ[i]; i++) {
        puts(environ[i]);
    }

    printf("user name: %s\n", getenv("USER"));

    return 0;
}