#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, size, head, dir, a[50], total = 0, temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter total number of cylinders: ");
    scanf("%d", &size);

    if (n < 1 || n > 50 || size < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0 || a[i] >= size) {
            printf("Invalid cylinder number.\n");
            return 1;
        }
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    if (head < 0 || head >= size) {
        printf("Invalid head position.\n");
        return 1;
    }

    printf("Enter direction (1=Higher, 0=Lower): ");
    scanf("%d", &dir);

    if (dir != 0 && dir != 1) {
        printf("Invalid direction.\n");
        return 1;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Seek sequence: ");

    if (dir == 1) {
        for (int i = 0; i < n; i++)
            if (a[i] >= head) {
                printf("%d ", a[i]);
                total += abs(head - a[i]);
                head = a[i];
            }

        if (head != size - 1) {
            total += abs(head - (size - 1));
            head = size - 1;
            printf("%d ", head);
        }

        for (int i = n - 1; i >= 0; i--)
            if (a[i] < head) {
                total += abs(head - a[i]);
                head = a[i];
                printf("%d ", head);
            }
    } else {
        for (int i = n - 1; i >= 0; i--)
            if (a[i] <= head) {
                printf("%d ", a[i]);
                total += abs(head - a[i]);
                head = a[i];
            }

        if (head != 0) {
            total += head;
            head = 0;
            printf("%d ", head);
        }

        for (int i = 0; i < n; i++)
            if (a[i] > head) {
                total += abs(head - a[i]);
                head = a[i];
                printf("%d ", head);
            }
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}