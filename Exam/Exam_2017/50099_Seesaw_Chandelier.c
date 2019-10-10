#include <stdio.h>
#include <stdlib.h>

long long idx_seq[17000] = {};
long long idx_ptr = 0;

int compare(const void *data1,const void *data2){
    long long *ptr1 = (long long *)data1;
    long long *ptr2 = (long long *)data2;
    if(*ptr1 > *ptr2){
        return 1;
    }else if(*ptr2 > *ptr1){
        return -1;
    }else{
        return 0;
    }
}

void seesaw(long long seq[],long long left,long long right){
    long long idx = -1;
    if(right-left+1 < 3){
        return;
    }
    for(long long i = left;i<=right && idx == -1;i++){
        long long left_sum = 0;
        long long right_sum = 0;
        long long extra = 1;
        if(i > left){
            for(long long j = i-1;j>=left;j--){
                left_sum += (extra * seq[j]);
                extra ++;
            }
        }
        extra = 1;
        if(i < right){
            for(long long j = i+1;j<=right;j++){
                right_sum += (extra * seq[j]);
                extra ++;
            }
        }
        if(left_sum == right_sum){
            idx = i;
        }
    }
    if(idx == -1){
        return;
    }else{
        idx_seq[idx_ptr] = idx;
        idx_ptr ++;
        seesaw(seq,left,idx-1);
        seesaw(seq,idx+1,right);
        return;
    }
}

int main(){
    long long n;
    scanf("%lld",&n);
    long long seq[17000] = {};
    for(long long i = 0;i<n;i++){
        scanf("%ld",&seq[i]);
    }
    seesaw(seq,0,n-1);
    qsort(idx_seq,idx_ptr,sizeof(long long),compare);
    for(int i = 0;i<idx_ptr;i++){
        printf("%d\n",idx_seq[i]);
    }
    return 0;
}