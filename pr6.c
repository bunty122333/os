#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t fork[5], room;

void *eat(void *p) {
    int i = (long)p;
    sem_wait(&room);
    sem_wait(&fork[i]);
    sem_wait(&fork[(i+1)%5]);

    printf("Philosopher %d eating\n", i);

    sem_post(&fork[i]);
    sem_post(&fork[(i+1)%5]);
    sem_post(&room);
    return NULL;
}

int main() {
    pthread_t p[5];
    int i;

    sem_init(&room, 0, 4);
    for (i = 0; i < 5; i++)
        sem_init(&fork[i], 0, 1);

    for (i = 0; i < 5; i++)
        pthread_create(&p[i], NULL, eat, (void *)(long)i);

    for (i = 0; i < 5; i++)
        pthread_join(p[i], NULL);

    return 0;
}
