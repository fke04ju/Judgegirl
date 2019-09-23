#include <stdio.h>
#include <stdlib.h>
#define maxn 32769
int friends[maxn][260] = {};
int friends_index[maxn] = {};
int participated[maxn] = {};

int main(){
    int n,e;
    scanf("%d%d",&n,&e);
    int a,b;
    for(int i = 0;i<e;i++){
        scanf("%d%d",&a,&b);
        friends[a][friends_index[a]] = b;
        friends_index[a]++;
        friends[b][friends_index[b]] = a;
        friends_index[b]++;
    }
    int send;
    while(scanf("%d",&send)!=EOF){
        participated[send] = 1;
        for(int i = 0;i<friends_index[send];i++){
            participated[friends[send][i]] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        if(participated[i] == 0){
            printf("%d\n",i);
        }
    }
}