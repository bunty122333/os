#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a[5], i, j, t;
    for (i = 0; i < 5; i++) scanf("%d", &a[i]);

    if (fork() == 0) {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4-i; j++)
                if (a[j] > a[j+1]) {
                    t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                }
        printf("Child ascending: ");
    } else {
        wait(NULL);
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4-i; j++)
                if (a[j] < a[j+1]) {
                    t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                }
        printf("Parent descending: ");
    }

    for (i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
