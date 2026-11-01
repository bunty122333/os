#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p1[2],p2[2];
    char name[100],ch;
    FILE *fp;

    pipe(p1);
    pipe(p2);

    if(fork()==0) {
        close(p1[1]);
        close(p2[0]);

        read(p1[0],name,sizeof(name));
        fp=fopen(name,"r");

        if(fp!=NULL) {
            while((ch=fgetc(fp))!=EOF)
                write(p2[1],&ch,1);
            fclose(fp);
        }

        close(p1[0]);
        close(p2[1]);
    }
    else {
        close(p1[0]);
        close(p2[1]);

        printf("Enter filename: ");
        scanf("%99s",name);
        write(p1[1],name,sizeof(name));
        close(p1[1]);

        while(read(p2[0],&ch,1)>0)
            putchar(ch);

        close(p2[0]);
        wait(NULL);
    }
    return 0;
}
