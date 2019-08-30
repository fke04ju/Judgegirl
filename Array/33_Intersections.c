#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    int a[n+2][n+2];
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++){
            a[i][j]=0;
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int intersections=0;
    int T_junctions=0;
    int turns=0;
    int dead_ends=0;
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            if(a[i][j]==1 && a[i-1][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i][j-1]==1){
                intersections+=1;
            }else if(a[i][j]==1 && (a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]==3)){
                T_junctions+=1;
            }else if(a[i][j]==1 && ((a[i-1][j]+a[i][j-1]==2 && a[i+1][j]+a[i][j+1]==0) || (a[i-1][j]+a[i][j+1]==2 && a[i+1][j]+a[i][j-1]==0) || (a[i+1][j]+a[i][j-1]==2 && a[i-1][j]+a[i][j+1]==0) || (a[i+1][j]+a[i][j+1]==2 && a[i-1][j]+a[i][j-1]==0))){
                turns+=1;
            }else if(a[i][j]==1 && a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]==1){
                dead_ends+=1;
            }
        }
    }
    printf("%d\n%d\n%d\n%d",intersections,T_junctions,turns,dead_ends);
}