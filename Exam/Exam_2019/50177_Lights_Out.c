#include <stdio.h>
 
int n;
int arr[5][5];
int check[25];
int result[25];
int min = 2147483647;
int ans[25];
int d[5][2] = {{-1,0},{0,1},{1,0},{0,-1},{0,0}};
 
int if_turn_off(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j] == 1){
                return 0;
            }
        }
    }
    return 1;
}
 
void turnoff(int x,int y){
    for(int i = 0;i<5;i++){
        if(x+d[i][0] >= 0 && x+d[i][0] < n && y+d[i][1] >= 0 && y+d[i][1] < n){
            arr[x+d[i][0]][y+d[i][1]] ^= 1;
        }
    }
}
 
void print(int idx){
    for(int i = 0;i<idx;i++){
        printf("%d%c",ans[i],(i<idx-1)?' ':'\n');
    }
    return;
}
 
void recursion(int idx,int now){
    if(idx == n*n || now == n*n){
        return;
    }
    if(if_turn_off()){
        if(idx < min){
            min = idx;
            for(int i = 0;i<idx;i++){
                ans[i] = result[i];
            }
        }
        result[idx-1] = 0;
        return;
    }
    for(int i = now;i<n*n;i++){
        if(check[i] == 0){
            turnoff(i/n,i%n);
            result[idx] = i;
            check[i] = 1;
            recursion(idx+1,i);
            check[i] = 0;
            turnoff(i/n,i%n);
        }
    }
}
 
int main(){
    scanf("%d",&n);
    int a;
    while(scanf("%d",&a)!=EOF){
        arr[a/n][a%n] = 1;
    }
    recursion(0,0);
    print(min);
}