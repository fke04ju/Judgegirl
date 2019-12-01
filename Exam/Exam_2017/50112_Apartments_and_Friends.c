#include <stdio.h>
#include <stdlib.h>
 
int min = 2147483647;
int table[12][12] = {};
int check[12] = {};
int result[12];
int n,m;

void find(int index,int d,int prev){
    if(d >= min){
        return;
    }
    if(index == n){
        if(d < min){
            min = d;
        }
        result[index-1] = 0;
        return;
    }
    int flag = 0;
    for(int i = 0;i<n;i++){
        if(check[i] == 0){
            int sm = 0;
            if(index > 0){
                for(int j = 0;j<index;j++){
                    if(table[result[j]][i] == 1){
                        sm += abs(index-j);
                    }
                    if(d+sm >= min){
                        return;
                    }
                }
                if(d+sm >= min){
                    return;
                }
            }
            result[index] = i;
            check[i] = 1;
            find(index+1,d+sm,i);
            check[i] = 0;
        }
    }
}
 
int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i = 0;i<m;i++){
        scanf("%d%d",&a,&b);
        table[a][b] = 1;
        table[b][a] = 1;
    }
    find(0,0,0);
    printf("%d\n",min);
}