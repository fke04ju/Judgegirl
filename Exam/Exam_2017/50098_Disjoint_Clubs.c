#include <stdio.h>
#include <stdlib.h>

unsigned long long int club[101] = {};
int stack[105];
int ptr = 0;
int printed = 0;

int find(int n,int k,int now_idx,int now_num,unsigned long long int now_set){
    if(k == now_num){
        return 1;
    }
    for(int i = now_idx;i<n;i++){
        if((now_set&club[i]) == (unsigned long long int)0){
            if(find(n,k,i+1,now_num+1,now_set|club[i])){
                stack[ptr] = i;
                ptr++;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int num,which;
    unsigned long long int one = 1;
    for(int i = 0;i<n;i++){
        scanf("%d",&num);
        for(int j = 0;j<num;j++){
            one = 1;
            scanf("%d",&which);
            club[i] |= (one<<which);
        }
    }
    find(n,k,0,0,0);
    for(int i = ptr-1;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}