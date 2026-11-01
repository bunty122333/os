#include <stdio.h>

int main() {
    int a[20],n,h,size,i,j,t,k=0,cur;
    int scan=0,clook=0;

    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter head and disk size: ");
    scanf("%d%d",&h,&size);

    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) {
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }

    while(k<n && a[k]<h) k++;

    cur=h;
    for(i=k;i<n;i++) {
        scan+=a[i]-cur;
        cur=a[i];
    }
    scan+=(size-1)-cur;
    cur=size-1;

    for(i=k-1;i>=0;i--) {
        scan+=cur-a[i];
        cur=a[i];
    }

    cur=h;
    for(i=k;i<n;i++) {
        clook+=a[i]-cur;
        cur=a[i];
    }

    if(k>0) {
        clook+=cur-a[0];
        cur=a[0];
        for(i=1;i<k;i++) {
            clook+=a[i]-cur;
            cur=a[i];
        }
    }

    printf("SCAN movement = %d\n",scan);
    printf("C-LOOK movement = %d\n",clook);
    return 0;
}
