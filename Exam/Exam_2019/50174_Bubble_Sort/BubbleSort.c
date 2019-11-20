#include <stdio.h>
#include "BubbleSort.h"
void BubbleSort(uint64_t input, uint64_t output[63]){
    for(int i = 0;i<63;i++){
        for(int j = 62;j>=0;j--){
            if((input >> (j+1))&1 && !((input >> j)&1)){
                input -= (((uint64_t)1)<<j);
            }
        }
        output[i] = input;
    }
    return;
}