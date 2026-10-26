#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int n, i, a[20], temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if (pid == 0) {
        printf("\nChild process: PID = %d\n", getpid());
        printf("Elements in reverse order: ");
        for (i = n - 1; i >= 0; i--)
            printf("%d ", a[i]);
        printf("\n");
        exit(0);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent process: PID = %d\n", getpid());

        for (i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

        printf("Sorted elements: ");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else {
        printf("Fork failed.\n");
    }

    return 0;
}