#include <stdio.h>
#include <stdlib.h>

int cmp(const void *data1,const void *data2){
    int *ptr1 = (int *)data1;
    int *ptr2 = (int *)data2;
    if(ptr1[0] > ptr2[0]){
        return 1;
    }else if(ptr1[0] < ptr2[0]){
        return -1;
    }else{
        if(ptr1[1] > ptr2[1]){
            return 1;
        }else{
            return -1;
        }
    }
    
}

void count(int **p[]){
    int c[513][2] = {};
    int len = 0;
    while(p[len] != NULL){
        c[len][0] = *p[len];
        c[len][1] = **p[len];
        len++;
    }
    int cnt[513][2] = {};
    int traced[513] = {};
    int ptr = 0;
    for(int i = 0;i<len;i++){
        if(traced[i] == 0){
            for(int j = i;j<len;j++){
                if(c[i][0] == c[j][0] && traced[j] == 0){
                    cnt[ptr][0] ++;
                    cnt[ptr][1] = c[i][1];
                    traced[j] = 1;
                }
            }
            ptr++;
        }
    }
    qsort(cnt,ptr,sizeof(int)*2,cmp);
    for(int i = 0;i<ptr;i++){
        printf("%d %d\n",cnt[i][1],cnt[i][0]);
    }
    return;
}