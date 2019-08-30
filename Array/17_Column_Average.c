#include <stdio.h>
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    int a[r][c];
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        //    printf("%d",a[i][j]);
        }
    }
 
    int average;
    for(j=0;j<c;j++){
        int sum=0;
        for(i=0;i<r;i++){
            sum+=a[i][j];
        }
        average=sum/r;
        printf("%d\n",average);
    }
}