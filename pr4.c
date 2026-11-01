#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
sem_t s;
pthread_mutex_t m;

void *fun(void *p) {
    sem_wait(&s);
    pthread_mutex_lock(&m);
    count++;
    printf("Count = %d\n", count);
    pthread_mutex_unlock(&m);
    sem_post(&s);
    return NULL;
}

int main() {
    pthread_t a, b;
    sem_init(&s, 0, 1);
    pthread_mutex_init(&m, NULL);

    pthread_create(&a, NULL, fun, NULL);
    pthread_create(&b, NULL, fun, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);

    return 0;
}
