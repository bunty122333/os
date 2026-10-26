
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10

int n, rounds;
sem_t forks[MAX];
sem_t room;

void *philosopher(void *arg) {
    int id = *(int *)arg;

    for (int i = 0; i < rounds; i++) {
        printf("Philosopher %d is thinking.\n", id + 1);

        sem_wait(&room);
        sem_wait(&forks[id]);
        sem_wait(&forks[(id + 1) % n]);

        printf("Philosopher %d is eating.\n", id + 1);

        sem_post(&forks[(id + 1) % n]);
        sem_post(&forks[id]);
        sem_post(&room);
    }

    return NULL;
}

int main() {
    pthread_t t[MAX];
    int id[MAX];

    printf("Enter number of philosophers (2-10): ");
    scanf("%d", &n);

    printf("Enter eating rounds per philosopher: ");
    scanf("%d", &rounds);

    if (n < 2 || n > MAX || rounds < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    sem_init(&room, 0, n - 1);

    for (int i = 0; i < n; i++) {
        sem_init(&forks[i], 0, 1);
        id[i] = i;
    }

    for (int i = 0; i < n; i++)
        pthread_create(&t[i], NULL, philosopher, &id[i]);

    for (int i = 0; i < n; i++)
        pthread_join(t[i], NULL);

    for (int i = 0; i < n; i++)
        sem_destroy(&forks[i]);

    sem_destroy(&room);
    return 0;
}
