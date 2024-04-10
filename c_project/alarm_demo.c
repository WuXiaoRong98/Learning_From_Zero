#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handle(int sig)
{
    puts("Alarm timeout");
    exit(0);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = sig_handle;

    if (sigaction(SIGALRM, &sa, NULL) < 0) {
        perror("sigaction");
        exit(-1);
    }

    alarm(10);

    sleep(20);

    printf("normal exit\n");

    exit(0);
}