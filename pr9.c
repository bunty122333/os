#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, a[50], visited[50] = {0};
    int total = 0, pos, min;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Enter between 1 and 50 requests.\n");
        return 1;
    }

    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek sequence: ");

    for (int i = 0; i < n; i++) {
        min = 1000000;
        pos = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(head - a[j]) < min) {
                min = abs(head - a[j]);
                pos = j;
            }
        }

        visited[pos] = 1;
        total += abs(head - a[pos]);
        head = a[pos];

        printf("%d ", head);
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}