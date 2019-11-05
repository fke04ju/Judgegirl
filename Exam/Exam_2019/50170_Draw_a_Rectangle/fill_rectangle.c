#include <stdio.h>
#include <stdlib.h>
void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill){
    int *ptr = upper_left;
    int count = 0;
    while(ptr != bottom_right){
        ptr ++;
        count ++;
    }
    ptr = upper_left;
    int r = count / n_col;
    int c = count % n_col;
    for(int i = 0;i<=r;i++){
        for(int j = 0;j<=c;j++){
            *(ptr+i*n_col+j) = fill;
        }
    }
    return;
}
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill){
    int count = 0;
    if(upper_right >= bottom_left){
        int *ptr = bottom_left;
        while(ptr <= upper_right){
            *ptr = fill;
            ptr++;
        }
    }else{
        int *ptr = upper_right;
        while(ptr != bottom_left){
            count ++;
            ptr++;
        }
        ptr = upper_right;
        int r,c;
        if(count % n_col == 0){
            c = 0;
            r = count / n_col;
        }else{
            c = n_col - count % n_col;
            r = count / n_col + 1;
        }
        for(int i = 0;i<=r;i++){
            for(int j = 0;j<=c;j++){
                *(ptr+i*n_col-j) = fill;
            }
        }
    }
    return;
}