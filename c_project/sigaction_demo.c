#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig)
{
    printf("Caught SIGUSR1)\n");
    exit(1);
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = handle_sigusr1;
    
    sigaction(SIGUSR1, &sa, NULL);

    while(1) { 
        perror("sigaction");
        sleep(1);
    }
    return 0;
}