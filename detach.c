#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func(void *arg)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("Tache %d : %d\n", (int)arg, i);
        usleep(1000000);
    }
}

int main(void)
{
    pthread_t tache1;
    pthread_attr_t attr; 
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&tache1, &attr, func, (void *)1);
    pthread_attr_destroy(&attr);
    return 0;
}