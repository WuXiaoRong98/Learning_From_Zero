#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

//kill -s SIGUSR1 pid
void signal_handler(int signum)
{
    printf("Caught signal %d\n", signum);
   // exit(1);
}
int main(int argc, char **argv)
{
    signal(SIGUSR1, signal_handler);

    sleep(30);

    printf("process exited\n");
    exit(0);
}