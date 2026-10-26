#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, dir, a[50], total = 0, temp, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Enter between 1 and 50 requests.\n");
        return 1;
    }

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            printf("Invalid request.\n");
            return 1;
        }
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    if (head < 0) {
        printf("Invalid head position.\n");
        return 1;
    }

    printf("Enter direction (1=Higher, 0=Lower): ");
    scanf("%d", &dir);

    if (dir != 0 && dir != 1) {
        printf("Invalid direction.\n");
        return 1;
    }

    for (i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Seek sequence: ");

    if (dir == 1) {
        for (i = 0; i < n; i++)
            if (a[i] >= head) {
                printf("%d ", a[i]);
                total += abs(head - a[i]);
                head = a[i];
            }

        for (i = 0; i < n; i++)
            if (a[i] < head) {
                total += abs(head - a[i]);
                head = a[i];
                printf("%d ", head);
            }
    } else {
        for (i = n - 1; i >= 0; i--)
            if (a[i] <= head) {
                printf("%d ", a[i]);
                total += abs(head - a[i]);
                head = a[i];
            }

        for (i = n - 1; i >= 0; i--)
            if (a[i] > head) {
                total += abs(head - a[i]);
                head = a[i];
                printf("%d ", head);
            }
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}