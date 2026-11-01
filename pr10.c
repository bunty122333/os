#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[20],done[20]={0};
    int n,head,i,j,min,pos,total=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter initial head: ");
    scanf("%d",&head);

    for(i=0;i<n;i++) {
        min=99999;

        for(j=0;j<n;j++) {
            if(!done[j] && abs(head-a[j])<min) {
                min=abs(head-a[j]);
                pos=j;
            }
        }

        total+=abs(head-a[pos]);
        head=a[pos];
        done[pos]=1;
    }

    printf("Total head movement = %d\n",total);
    return 0;
}
