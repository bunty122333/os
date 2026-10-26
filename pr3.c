
#include <stdio.h>
#include <pthread.h>

int count, n;
pthread_mutex_t lock;

void *increase(void *arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&lock);
        count++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("Enter initial counter value: ");
    scanf("%d", &count);

    printf("Enter number of increments per thread: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of increments.\n");
        return 1;
    }

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increase, NULL);
    pthread_create(&t2, NULL, increase, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", count);

    pthread_mutex_destroy(&lock);
    return 0;
}
