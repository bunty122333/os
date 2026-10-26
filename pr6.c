#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];
    int count = 0, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter maximum need matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Enter available resources: ");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        printf("System is in safe state.\nSafe sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safe[i]);
        printf("\n");
    } else {
        printf("System is not in a safe state.\n");
    }

    return 0;
}