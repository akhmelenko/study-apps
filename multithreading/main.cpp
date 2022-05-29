#include <pthread.h> // pthread_t, pthread_create()
#include <stdio.h>   // print()
#include <stdlib.h>  // exit()

#define THREADS_NUMBER 11

void *PrintHello(void *tid)
{
    printf("Hello from thead# %d\n\r", *(int *)tid);
    pthread_exit(nullptr);
}

int main()
{
    pthread_t threads[THREADS_NUMBER];
    int tid[THREADS_NUMBER];
    int status;
    for (int i = 0; i < THREADS_NUMBER; i++)
    {
        tid[i] = i;
        printf("Main program, start thread# %d\n\r", (int)tid[i]);
        status = pthread_create(&threads[i], nullptr, PrintHello, (void *)&tid[i]);
        printf("status = %d thread=%d\n\r", status, threads[i]);
        if (status != 0)
        {
            printf("Sorry, pthread_create error: %d\n\r", status);
            exit(-1);
        }
    }

    while (1)
        ;
    exit(0);
}
