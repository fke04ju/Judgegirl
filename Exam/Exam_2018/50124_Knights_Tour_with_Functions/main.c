#include <stdio.h>
#include "validMoveNum.h"
#include "nextMove.h"
#define MAXN 100

int r[MAXN*MAXN];
int c[MAXN*MAXN];
int visited[MAXN][MAXN]={0};
int ans[MAXN][MAXN] = {0};
int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int stop[MAXN*MAXN] = {};
int step[MAXN*MAXN] = {};

int end(int m){
    for(int i = 0;i<m;i++){
        if(stop[i] == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&r[i],&c[i]);
        visited[r[i]][c[i]] = 1;
        ans[r[i]][c[i]] = (i+1)*10000;
    }
    while(end(m) == 1){
        for(int i = 0;i<m;i++){
            int next = nextMove(r[i],c[i],n,visited);
            if(next == -1){
                stop[i] = 1;
            }else{
                step[i]++;
                r[i]+=move[next][0];
                c[i]+=move[next][1];
                visited[r[i]][c[i]] = 1;
                ans[r[i]][c[i]] = (i+1)*10000+step[i];
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d%c",ans[i][j],(j<n-1)?' ':'\n');
        }
    }
}