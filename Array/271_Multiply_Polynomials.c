#include <stdio.h>
 
int main() {
    int i,j;
    int n,m,x;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[i]=x;
//        printf("%d",a[i]);
    }
    scanf("%d",&m);
    int b[m];
    for(i=0;i<m;i++){
        scanf("%d",&x);
        b[i]=x;
//        printf("%d",b[i]);
    }
    int c[(n+m)];
    for(i=0;i<(n+m);i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[(i+j)]+=(a[i]*b[j]);
        }
    }
    printf("%d",c[0]);
    for(i=1;i<(m+n-1);i++){
        printf(" %d",c[i]);
    }
}