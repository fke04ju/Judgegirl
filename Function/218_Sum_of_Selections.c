#include <stdio.h>
 
int c(int n,int m){
    int sum=1;
    int k;
    int i,j;
    for(i=1;i<=m;i++){
        int up=1;
        int down=1;
        int t=1;
        for(j=n;j>n-i;j--){
            up*=j;
            down*=t;
            t++;
        }
        k=up/down;
        sum+=k;
    }
    return sum;
}
 
int main() {
    int m,n;
    scanf("%d%d",&n,&m);
    c(n,m);
    printf("%d",c(n,m));
    return 0;
}