#include <stdio.h>
#include<stdint.h>
void printMatrix(uint64_t *matrix){
    printf("%llu\n",*matrix);
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            printf("%llu",((*matrix)>>(i*8+j))%2);
        }
        puts("");
    }
    return;
}
void rotateMatrix(uint64_t *matrix){
    uint64_t newmatrix = 0;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            uint64_t tmp = 0;
            tmp |= (*matrix >> (i*8+j))%2;
            newmatrix |= tmp<<(j*8+(7-i));
        }
    }
    *matrix = newmatrix;
    return;
}
void transposeMatrix(uint64_t *matrix){
    uint64_t newmatrix = 0;
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            uint64_t tmp = 0;
            tmp |= (*matrix >> (i*8+j))%2;
            newmatrix |= tmp << (j*8+i);
        }
    }
    *matrix = newmatrix;
    return;
}