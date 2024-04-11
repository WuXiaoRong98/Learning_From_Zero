#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void wait_child(int sig)
{
    printf("父进程回收子进程");
    while(waitpid(-1, NULL, WNOHANG) > 0) {
        continue;
    }
}
int main()
{

    struct sigaction sa = {0};

    sigemptyset(&sa.sa_mask);
    sa.sa_handler = wait_child;
    sa.sa_flags = 0;

    sigaction(SIGCHLD, &sa, NULL);

    switch(fork()) {
        case -1:
            printf("fork error\n");
            break;
        case 0:
            printf("Child process %d\n", getpid());
            sleep(1);
            printf("child exit\n");
            _exit(0);
        default:
            break;
    }

    sleep(10);
    printf("parent process exit\n");
    exit(0);

}