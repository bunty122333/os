#include <stdio.h>
#include <string.h>

struct Contact {
    char name[20], phone[15];
};

int main() {
    struct Contact a[20];
    int n = 0, ch, i, j;
    char name[20];

    do {
        printf("\n1.Create 2.View 3.Insert");
        printf("\n4.Delete 5.Modify 6.Exit\n");
        scanf("%d", &ch);

        if (ch == 1 || ch == 3) {
            if (ch == 1) n = 0;
            printf("Enter name and phone: ");
            scanf("%19s %14s", a[n].name, a[n].phone);
            n++;
        }
        else if (ch == 2) {
            for (i = 0; i < n; i++)
                printf("%s %s\n", a[i].name, a[i].phone);
        }
        else if (ch == 4 || ch == 5) {
            printf("Enter name: ");
            scanf("%19s", name);

            for (i = 0; i < n; i++)
                if (strcmp(a[i].name, name) == 0) break;

            if (i == n) printf("Not found\n");
            else if (ch == 5) {
                printf("New phone: ");
                scanf("%14s", a[i].phone);
            }
            else {
                for (j = i; j < n - 1; j++) a[j] = a[j + 1];
                n--;
            }
        }
    } while (ch != 6);

    return 0;
}
