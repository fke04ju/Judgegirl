#include <stdio.h>
int bingo(const unsigned long long int *board, int *rowColumn){
    unsigned long long int one;
    unsigned long long int row[8] = {};
    one = 255;
    for(int i = 0;i<8;i++){
        row[i] = one << (8*i);
    }
    unsigned long long int col[8] = {};
    one = 1;
    for(int i = 0;i<7;i++){
        unsigned long long int tmp = one;
        tmp <<= 8;
        one |= tmp;
    }
    col[0] = one;
    for(int i = 1;i<8;i++){
        one <<= 1;
        col[i] = one;
    }
    unsigned long long int diag[2] = {};
    one = 1;
    for(int i = 0;i<8;i++){
        diag[0] |= one;
        one <<= 9;
    }
    one = 128;
    for(int i = 0;i<7;i++){
        diag[1] |= one;
        one <<= 7;
    }
    for(int i = 7;i>=0;i--){
        if((*board & row[i]) == row[i]){
            *rowColumn = 7-i;
            return 1;
        }
    }
    for(int i = 7;i>=0;i--){
        if((*board & col[i]) == col[i]){
            *rowColumn = 7-i;
            return 2;
        }
    }
    if((*board & diag[0]) == diag[0]){
        *rowColumn = 0;
        return 3;
    }
    if((*board & diag[1]) == diag[1]){
        *rowColumn = 1;
        return 3;
    }
    return 0;
}