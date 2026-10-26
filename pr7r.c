#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>

int main() {
    char text[1000] = {0}, report[300];
    int fd, n, chars, words = 0, lines = 0, inword = 0;

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    fd = open("fifo1", O_RDONLY);
    n = read(fd, text, sizeof(text) - 1);
    close(fd);

    chars = n > 0 ? n : 0;

    for (int i = 0; i < chars; i++) {
        if (text[i] == '\n')
            lines++;

        if (isspace((unsigned char)text[i]))
            inword = 0;
        else if (!inword) {
            words++;
            inword = 1;
        }
    }

    if (chars > 0 && text[chars - 1] != '\n')
        lines++;

    snprintf(report, sizeof(report),
             "Characters: %d\nWords: %d\nLines: %d\n",
             chars, words, lines);

    FILE *f = fopen("result.txt", "w");
    fprintf(f, "%s", report);
    fclose(f);

    fd = open("fifo2", O_WRONLY);
    write(fd, report, strlen(report));
    close(fd);

    printf("Report saved in result.txt\n");
    return 0;
}