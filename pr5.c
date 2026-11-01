#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;
pthread_mutex_t m;
int item;

void *producer(void *p) {
    sem_wait(&empty);
    pthread_mutex_lock(&m);
    item = 10;
    printf("Produced: %d\n", item);
    pthread_mutex_unlock(&m);
    sem_post(&full);
    return NULL;
}

void *consumer(void *p) {
    sem_wait(&full);
    pthread_mutex_lock(&m);
    printf("Consumed: %d\n", item);
    pthread_mutex_unlock(&m);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&m, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
