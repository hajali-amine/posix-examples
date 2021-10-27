#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct
{
    float taille;
    float poids;
} type_donneePartagee;

pthread_mutex_t verrou;
type_donneePartagee donneePartagee;

void *tache1(void *arg)
{
    type_donneePartagee ma_donneePartagee;
    int i = 0;
    while (i < 10)
    {
        pthread_mutex_lock(&verrou);
        ma_donneePartagee = donneePartagee;
        pthread_mutex_unlock(&verrou);
        printf("La tache %s vient de lire la donnee partagee\n", (char *)arg);
        usleep(1000000);
        i++;
    }
}

void *tache2(void *arg)
{
    int i = 0;
    while (i < 10)
    {
        pthread_mutex_lock(&verrou);
        donneePartagee.taille = 100 + rand() % 101;
        donneePartagee.poids = 10 + rand() % 101;
        pthread_mutex_unlock(&verrou);
        printf("La tache %s vient de modifier la donnee partagee\n", (char *)arg);
        usleep(1000000);
        i++;
    }
}

int main(void)
{
    pthread_t th1, th2;
    pthread_mutex_init(&verrou, NULL);
    donneePartagee.taille = 100 + rand() % 101;
    donneePartagee.poids = 10 + rand() % 101;
    pthread_create(&th1, NULL, tache1, "1");
    pthread_create(&th2, NULL, tache2, "2");
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}