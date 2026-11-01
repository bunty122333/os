#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[200]={0}, result[200];
    int f,i,words=0,lines=0,in=0;

    mkfifo("p1",0666);
    mkfifo("p2",0666);

    f=open("p1",O_RDONLY);
    read(f,s,199);
    close(f);

    for(i=0;s[i];i++) {
        if(s[i]=='\n') lines++;
        if(isspace((unsigned char)s[i])) in=0;
        else if(!in) { words++; in=1; }
    }

    sprintf(result,"Characters: %d\nWords: %d\nLines: %d\n",
            (int)strlen(s),words,lines);

    FILE *fp=fopen("result.txt","w");
    fprintf(fp,"%s",result);
    fclose(fp);

    f=open("p2",O_WRONLY);
    write(f,result,strlen(result)+1);
    close(f);
    return 0;
}
