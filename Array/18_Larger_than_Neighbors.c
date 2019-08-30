#include <stdio.h>
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    int a[r+2][c+2];
    int i,j;
    for(i=0;i<r+2;i++){
        for(j=0;j<c+2;j++){
            a[i][j]=0;
        }
    }
    for(i=1;i<r+1;i++){
        for(j=1;j<c+1;j++){
            scanf("%d",&a[i][j]);
        //    printf("%d",a[i][j]);
        }
    }
    for(i=1;i<r+1;i++){
        for(j=1;j<c+1;j++){
            if((a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j]) && (a[i][j]>a[i][j-1]  && a[i][j]>a[i][j+1])){
                printf("%d\n",a[i][j]);
            }
        }
    }
}