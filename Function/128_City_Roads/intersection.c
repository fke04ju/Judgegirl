#include "intersection.h"
void intersection(int map[100][100], int result[4]){
    int a[102][102];
    for(int i=0;i<4;i++){
        result[i]=0;
    }
    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            a[i+1][j+1]=map[i][j];
        }
    }
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++){
            if(a[i][j]==1 && a[i-1][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i][j-1]==1){
                result[0]+=1;
            }else if(a[i][j]==1 && (a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]==3)){
                result[1]+=1;
            }else if(a[i][j]==1 && ((a[i-1][j]+a[i][j-1]==2 && a[i+1][j]+a[i][j+1]==0) || (a[i-1][j]+a[i][j+1]==2 && a[i+1][j]+a[i][j-1]==0) || (a[i+1][j]+a[i][j-1]==2 && a[i-1][j]+a[i][j+1]==0) || (a[i+1][j]+a[i][j+1]==2 && a[i-1][j]+a[i][j-1]==0))){
                result[2]+=1;
            }else if(a[i][j]==1 && a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1]==1){
                result[3]+=1;
            }
        }
    }
}