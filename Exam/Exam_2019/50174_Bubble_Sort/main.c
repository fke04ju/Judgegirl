#include <stdio.h>
#include <stdint.h>
#include <inttypes.h> 
#include "BubbleSort.h"
#define N 63
int main(){
    uint64_t input;
    uint64_t output[N];
 
    scanf("%I64lu", &input);
    BubbleSort(input, output);
    for(int i = 0; i < N; i++)
        printf("%" PRIx64 "\n", output[i]);
    return 0;
}