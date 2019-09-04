#include <stdio.h>

int adjlist[1000][1000] = {};

int cycle(int n,int p,int pick_n,int ans[1000],int pick[1000]){
    if(pick_n == n){
        if(adjlist[p][0] == 1){
            for(int i = 0;i<n;i++){
                printf("%d ",ans[i]);
            }
            printf("0\n");
            return 1;
        }else{
            return 0;
        }
    }
    for(int i = 0;i<n;i++){
        if(!pick[i] && adjlist[p][i]){
            ans[pick_n] = i;
            pick[i] = 1;
            if(cycle(n,i,pick_n+1,ans,pick)){
                return 1;
            }
            pick[i] = 0;
        }
    }
    return 0;
}

int main(){
    int c,n;
    scanf("%d%d",&c,&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        adjlist[a][b] = 1;
        adjlist[b][a] = 1;
    }
    int ans[1000] = {};
    int pick[1000] = {};
    pick[0] = 1;
    if(!cycle(c,0,1,ans,pick)){
        printf("NO SOLUTION\n");
    }
}