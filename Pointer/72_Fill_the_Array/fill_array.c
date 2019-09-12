#include "fill_array.h"
void fill_array(int *ptr[], int n){
    int *tmp = ptr[0];
    while(tmp < ptr[n-1]){
        *tmp = -1;
        tmp++;
    }
    for(int i = 0;i<n;i++){
        *ptr[i] = i;
    }
    int *start = ptr[0];
    int left = *ptr[0];
    while(start < ptr[n-1]){
        if(*start == -1){
            int right = 0;
            while(*(start + right) == -1){
                right++;
            }
            for(int i = 0;i<right;i++){
                *(start + i) = (left + *(start+right));
            }
            start += right;
        }else{
            left = *start;
            start++;
        }
    }
    return;
}