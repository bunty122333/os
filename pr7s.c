#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char text[1000];
    int fd;

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    printf("Enter text (type END on a new line to finish):\n");

    text[0] = '\0';

    while (1) {
        char line[200];

        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        if (strcmp(line, "END\n") == 0)
            break;

        if (strlen(text) + strlen(line) >= sizeof(text)) {
            printf("Text limit reached.\n");
            break;
        }

        strcat(text, line);
    }

    fd = open("fifo1", O_WRONLY);
    write(fd, text, strlen(text));
    close(fd);

    fd = open("fifo2", O_RDONLY);
    char result[500] = {0};
    int n = read(fd, result, sizeof(result) - 1);
    if (n > 0)
        printf("\nReport from receiver:\n%s", result);
    close(fd);

    return 0;
}