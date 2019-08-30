#include <stdio.h>
 
int main() {
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m,k;
    scanf("%d",&m);
    int b[m];
    for(i=0;i<m;i++){
        b[i]=0;
    }
    for(i=0;i<n;i++){
        k=a[i]%m;
        b[k]+=1;
    }
    for(i=0;i<m;i++){
        printf("%d\n",b[i]);
    }
}