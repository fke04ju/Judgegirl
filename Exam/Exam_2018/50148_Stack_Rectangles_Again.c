#include <stdio.h>
int n;
int arr[250][2];
int max_sum,max_height;


void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
void recursion(int now,int height,int now_x,int now_y,int total){
#ifdef SMALLONLARGE

#ifdef MAXAREASUM
    if(now == n){
        if(max_height < height || (max_height == height && max_sum < total)){
            max_height = height;
            max_sum = total;
        }
        return;
    }
#endif

#ifdef MINAREASUM
    if(now == n){
        if(max_height < height || (max_height == height && max_sum > total)){
            max_height = height;
            max_sum = total;
        }
        return;
    }
#endif

    if(arr[now][0] <= now_x && arr[now][1] <= now_y){
        recursion(now+1,height+1,arr[now][0],arr[now][1],total+arr[now][0]*arr[now][1]);
    }
    recursion(now+1,height,now_x,now_y,total);

#endif

#ifdef LARGEONSMALL

#ifdef MAXAREASUM
    if(now == n){
        if(max_height < height || (max_height == height && max_sum < total)){
            max_height = height;
            max_sum = total;
        }
        return;
    }
#endif

#ifdef MINAREASUM
    if(now == n){
        if(max_height < height || (max_height == height && max_sum > total)){
            max_height = height;
            max_sum = total;
        }
        return;
    }
#endif

    if(arr[now][0] >= now_x && arr[now][1] >= now_y){
        recursion(now+1,height+1,arr[now][0],arr[now][1],total+arr[now][0]*arr[now][1]);
    }
    recursion(now+1,height,now_x,now_y,total);
    
#endif
}
 
int main(){
#ifdef MAXAREASUM
    max_sum = 0;
    max_height = 0;
#endif
#ifdef MINAREASUM
    max_sum = 2147483647;
    max_height = 0;
#endif
    int sum = 0,height = 0;
    int now_x,now_y;
#ifdef SMALLONLARGE
    now_x = 2147483647,now_y = 2147483647;
#endif
#ifdef LARGEONSMALL
    now_x = -2147483648,now_y =-2147483648;
#endif
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        if(arr[i][0] < arr[i][1]){
            swap(&arr[i][0],&arr[i][1]);
        }
    }
    recursion(0,0,now_x,now_y,0);
    printf("%d %d\n",max_height,max_sum);
}