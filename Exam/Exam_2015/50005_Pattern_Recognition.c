#include <stdio.h>

int diff(int a,int b){
    if(a > b){
        return a-b;
    }else{
        return b-a;
    }
}

int matching(int arr[2][10][10],int k,int m,int d,int d2,int r,int c){
    int sum_1 = 0;
    int mismatch = 0;
    for(int i = 0;i<k;i++){
        for(int j = 0;j<k;j++){
            sum_1 += arr[0][r+i][c+j];
            if(arr[0][r+i][c+j] != arr[1][i][j]){
                mismatch ++;
            }
        }
    }
    int dif = diff(sum_1,d2);
    if(mismatch <= m && dif <= d){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n,k,m,d;
    scanf("%d%d%d%d",&n,&k,&m,&d);
    int arr[2][10][10] = {};
    int d2 = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&arr[0][i][j]);
        }
    }
    for(int i = 0;i<k;i++){
        for(int j = 0;j<k;j++){
            scanf("%d",&arr[1][i][j]);
            d2 += arr[1][i][j];
        }
    }
    int last_rc[2] = {-1,-1};
    for(int i = 0;i<n-k+1;i++){
        for(int j = 0;j<n-k+1;j++){
            if(matching(arr,k,m,d,d2,i,j)){
                last_rc[0] = i;
                last_rc[1] = j;
            }
        }
    }
    printf("%d %d\n",last_rc[0],last_rc[1]);
}