#include <stdio.h>

int k,n,m;
int ans = 0;
int arr[25];

void pick(int arr[],int index,int len,int sum){
    if(index == n){
        if(sum <= m && len >= k){
            ans++;
        }
        return;
    }
    if(sum + arr[index] <= m){
        pick(arr,index+1,len+1,sum+arr[index]);
    }
    pick(arr,index+1,len,sum);
}

int main(){
    scanf("%d%d%d",&k,&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    pick(arr,0,0,0);
    printf("%d\n",ans);
}