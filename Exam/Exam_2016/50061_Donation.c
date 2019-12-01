#include <stdio.h>

int N;
int table[64][64];
int money[64];
int check[64];
int max = 0;

void donation(int index,int sum){
    if(index == N){
        if(sum > max){
            max = sum;
        }
        return;
    }
    donation(index+1,sum);
    for(int i = 0;i<index;i++){
        if(check[i] == 1 && table[i][index] == 1){
            return;
        }
    }
    check[index] = 1;
    donation(index+1,sum+money[index]);
    check[index] = 0;
}

int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        scanf("%d",&money[i]);
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&table[i][j]);
        }
    }
    donation(0,0);
    printf("%d\n",max);
}