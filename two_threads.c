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
    pthread_t tache1, tache2;
    int res = pthread_create(&tache1, NULL, func, (void *)1);
    pthread_create(&tache2, NULL, func, (void *)2);
    pthread_join(tache1, NULL);
    pthread_join(tache2, NULL);
    return 0;
}