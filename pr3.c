#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ch;
    printf("1.Zombie 2.Orphan: ");
    scanf("%d", &ch);

    if (fork() == 0) {
        if (ch == 2) {
            sleep(2);
            printf("Orphan child running\n");
        }
    } else {
        if (ch == 1) {
            sleep(3);
            wait(NULL);
            printf("Zombie collected\n");
        } else {
            printf("Parent exits\n");
            return 0;
        }
    }
    return 0;
}
