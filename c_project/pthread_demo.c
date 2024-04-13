#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_routine(void *args)
{
    printf("新线程： pid %d tid %ld\n", getpid(), pthread_self());
    sleep(3);
    //return (void *)0;
    pthread_exit((void *)0);
}

int main(int argc, char **argv)
{
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, new_thread_routine, NULL);
    if (ret != 0) {
        printf("Error: pthread_create\n");
        exit(-1);
    }

    pthread_join(tid, NULL);

    printf("主线程： pid %d tid %ld\n", getpid(), pthread_self());
    sleep(2);
    exit(0);
}