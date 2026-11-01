#include <stdio.h>
int main() {
    int a[10][10], m[10][10], need[10][10];
    int av[10], done[10]={0}, n,r,i,j,k,count=0,flag;

    printf("Enter processes and resources: ");
    scanf("%d%d",&n,&r);

    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++) scanf("%d",&a[i][j]);

    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++) scanf("%d",&m[i][j]);

    printf("Enter available resources: ");
    for(j=0;j<r;j++) scanf("%d",&av[j]);

    for(i=0;i<n;i++)
        for(j=0;j<r;j++) need[i][j]=m[i][j]-a[i][j];

    while(count<n) {
        flag=0;
        for(i=0;i<n;i++) {
            if(done[i]==0) {
                for(j=0;j<r;j++)
                    if(need[i][j]>av[j]) break;

                if(j==r) {
                    for(k=0;k<r;k++) av[k]+=a[i][k];
                    printf("P%d ",i);
                    done[i]=1; count++; flag=1;
                }
            }
        }
        if(flag==0) break;
    }
    if(count==n) printf("\nSafe state");
    else printf("\nUnsafe state");
    return 0;
}
