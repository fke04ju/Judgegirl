#include <stdio.h>
int n;
int arr[250][2];
int max_sum = 0,max_height = 0;
 
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void recursion(int now,int sum,int height,int now_x,int now_y){
    if(now == n){
        if(max_height < height || (max_height == height && max_sum < sum)){
            max_height = height;
            max_sum = sum;
        }
        return;
    }
    if(arr[now][0] <= now_x && arr[now][1] <= now_y){
        recursion(now+1,sum+now,height+1,arr[now][0],arr[now][1]);
    }
    recursion(now+1,sum,height,now_x,now_y);
}
 
int main(){
    int sum = 0,height = 0,now_x = 2147483647,now_y = 2147483647;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        if(arr[i][0] < arr[i][1]){
            swap(&arr[i][0],&arr[i][1]);
        }
    }
    recursion(0,0,0,now_x,now_y);
    printf("%d %d\n",max_height,max_sum);
}