#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int p1[2], p2[2];
    char filename[100], content[1000] = {0};
    char buffer[1000];
    pid_t pid;

    pipe(p1);
    pipe(p2);

    printf("Enter filename: ");
    scanf("%99s", filename);

    pid = fork();

    if (pid == 0) {
        close(p1[1]);
        close(p2[0]);

        int n = read(p1[0], filename, sizeof(filename) - 1);
        if (n <= 0)
            exit(1);
        filename[n] = '\0';
        close(p1[0]);

        FILE *f = fopen(filename, "r");

        if (f == NULL) {
            strcpy(content, "File not found.\n");
        } else {
            fread(content, 1, sizeof(content) - 1, f);
            fclose(f);
        }

        write(p2[1], content, strlen(content) + 1);
        close(p2[1]);
        exit(0);
    } else if (pid > 0) {
        close(p1[0]);
        close(p2[1]);

        write(p1[1], filename, strlen(filename));
        close(p1[1]);

        wait(NULL);

        int n = read(p2[0], buffer, sizeof(buffer) - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("\nFile contents:\n%s", buffer);
        }

        close(p2[0]);
    }

    return 0;
}