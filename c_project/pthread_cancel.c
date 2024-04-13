#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_routine(void *args)
{
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    printf("新线程： pid %d tid %ld\n", getpid(), pthread_self());
    sleep(1);
    pthread_exit((void *)0);
}

int main(int argc, char **argv)
{
    pthread_t tid;
    void *retval;

    int ret = pthread_create(&tid, NULL, new_thread_routine, NULL);
    if (ret != 0) {
        printf("Error: pthread_create\n");
        exit(-1);
    }
    pthread_cancel(tid);

    pthread_join(tid, &retval);

    printf("*retval: %ld\n", (long)retval);

    printf("主线程： pid %d tid %ld\n", getpid(), pthread_self());
    sleep(2);
    exit(0);
}