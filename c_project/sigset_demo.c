#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig)
{
    printf("执行信号处理函数。。。。\n");
}

int main(int argc, char *argv[])
{
    printf("SIGINT DESC: %s\n", sys_siglist[SIGINT]);
    printf("SIGUSR1 DESC: %s\n", sys_siglist[SIGUSR1]);

    printf("================================================================\n");
    printf("SIGINT DESC: %s\n", strsignal(SIGINT));
    printf("SIGUSR1 DESC: %s\n", strsignal(SIGUSR1));

     printf("================================================================\n");
    psignal(SIGINT, "SIGINT DESC");
    psignal(SIGUSR1, "SIGUSR1 DESC");

    struct sigaction sig = {0};
    sigset_t sig_set;

    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;

    sigaction(SIGINT, &sig, NULL);

    sigemptyset(&sig_set);
    sigaddset(&sig_set, SIGINT);

    sigprocmask(SIG_BLOCK, &sig_set, NULL);

    raise(SIGINT);

    sleep(2);
    printf("sleep end\n");

    sigprocmask(SIG_UNBLOCK, &sig_set, NULL);

    exit(0);

    exit(0);
}