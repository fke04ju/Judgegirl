#include <stdio.h>
int main(){
    int n,m,x;
    int i,j;
    int modulo;
    scanf("%d%d",&n,&m);
    int a[m][3];
    for(i=0;i<m;i++){
        for(j=0;j<2;j++){
            a[i][j]=0;
        }
        a[i][2]=10000000;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x);
        modulo=x%m;
        a[modulo][0]+=x;
        if(a[modulo][1]<=x){
            a[modulo][1]=x;
        }else{
 
        }
        if(a[modulo][2]<=x){
 
        }else{
            a[modulo][2]=x;
        }
    }
    for(i=0;i<m-1;i++){
        for(j=0;j<2;j++){
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][2]);
    }
    for(i=m-1;i<m;i++){
        for(j=0;j<2;j++){
            printf("%d ",a[i][j]);
        }
        printf("%d",a[i][2]);
    }
}