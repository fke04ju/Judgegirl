#include <stdio.h>

int two_point(int a,int b,int c,int d){
    if(b == d){
        return 1;
    }
    if(a == c){
        return 2;
    }
    if(a-c == d-b){
        return 3;
    }
    if(a-c == b-d){
        return 4;
    }
    return 0;
}

int main(){
    int l,x,y;
    scanf("%d%d%d",&l,&x,&y);
    int arr[x][y];
    for(int i = 0;i<x;i++){
        for(int j = 0;j<y;j++){
            arr[i][j] = 0;
        }
    }
    int n;
    int before_x,before_y;
    int after_x,after_y;
    int cnt_n = 1;
    int cnt_num = 2;
    while(scanf("%d",&n)!=EOF){
        scanf("%d%d",&before_x,&before_y);
        for(int i = 1;i<n;i++){
            scanf("%d%d",&after_x,&after_y);
            int type = two_point(before_x,before_y,after_x,after_y);
            if(type == 1){ // 橫排
                if(before_x < after_x){
                    for(int i = before_x;i<=after_x;i++){
                        arr[before_y][i] = 1;
                    }
                }else{
                    for(int i = after_x;i<=before_x;i++){
                        arr[before_y][i] = 1;
                    }
                }
            }else if(type == 2){ // 直排
                if(before_y < after_y){
                    for(int i = before_y;i<=after_y;i++){
                        arr[i][before_x] = 1;
                    }
                }else{
                    for(int i = after_y;i<=before_y;i++){
                        arr[i][before_x] = 1;
                    }
                }
            }else if(type == 3){ // 斜排 左上<->右下
                if(before_x < after_x){
                    int tmp_x = before_x,tmp_y = before_y;
                    arr[tmp_y][tmp_x] = 1;
                    while(tmp_x != after_x && tmp_y != after_y){
                        tmp_x ++;
                        tmp_y --;
                        arr[tmp_y][tmp_x] = 1;
                    }
                }else{
                    int tmp_x = before_x,tmp_y = before_y;
                    arr[tmp_y][tmp_x] = 1;
                    while(tmp_x != after_x && tmp_y != after_y){
                        tmp_x --;
                        tmp_y ++;
                        arr[tmp_y][tmp_x] = 1;
                    }
                }
            }else if(type == 4){ // 斜排 左下<->右上
                if(before_x < after_x){
                    int tmp_x = before_x,tmp_y = before_y;
                    arr[tmp_y][tmp_x] = 1;
                    while(tmp_x != after_x && tmp_y != after_y){
                        tmp_x ++;
                        tmp_y ++;
                        arr[tmp_y][tmp_x] = 1;
                    }
                }else{
                    int tmp_x = before_x,tmp_y = before_y;
                    arr[tmp_y][tmp_x] = 1;
                    while(tmp_x != after_x && tmp_y != after_y){
                        tmp_x --;
                        tmp_y --;
                        arr[tmp_y][tmp_x] = 1;
                    }
                }
            }else{
                printf("ERROR %d %d\n",cnt_n,cnt_num);
                return 0;
            }
            before_x = after_x;
            before_y = after_y;
            cnt_num++;
        }
        cnt_n++;
        cnt_num = 2;
    }
    for(int i = x-1;i>=0;i--){
        for(int j = 0;j<y;j++){
            printf("%d",arr[i][j]);
        }
        puts("");
    }
}