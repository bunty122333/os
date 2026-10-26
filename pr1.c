#include <stdio.h>
#include <string.h>

struct Contact {
    char name[30], phone[15];
};

int main() {
    struct Contact c[50];
    int n = 0, ch, i, pos;
    char name[30];

    while (1) {
        printf("\n1.Add  2.Display  3.Search  4.Delete  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter name: ");
            scanf(" %29[^\n]", c[n].name);
            printf("Enter phone: ");
            scanf("%14s", c[n].phone);
            n++;
        }
        else if (ch == 2) {
            for (i = 0; i < n; i++)
                printf("%s - %s\n", c[i].name, c[i].phone);
        }
        else if (ch == 3) {
            printf("Enter name to search: ");
            scanf(" %29[^\n]", name);
            for (i = 0; i < n; i++)
                if (strcmp(name, c[i].name) == 0)
                    printf("Found: %s - %s\n", c[i].name, c[i].phone);
        }
        else if (ch == 4) {
            printf("Enter contact number to delete (1 to %d): ", n);
            scanf("%d", &pos);
            if (pos >= 1 && pos <= n) {
                for (i = pos - 1; i < n - 1; i++)
                    c[i] = c[i + 1];
                n--;
                printf("Contact deleted.\n");
            } else {
                printf("Invalid number.\n");
            }
        }
        else if (ch == 5) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}