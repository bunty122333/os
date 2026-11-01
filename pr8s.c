#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char s[200], result[200]={0};
    int f;

    mkfifo("p1",0666);
    mkfifo("p2",0666);

    printf("Enter sentence: ");
    fgets(s,200,stdin);

    f=open("p1",O_WRONLY);
    write(f,s,sizeof(s));
    close(f);

    f=open("p2",O_RDONLY);
    read(f,result,sizeof(result)-1);
    close(f);

    printf("Result:\n%s",result);
    return 0;
}
