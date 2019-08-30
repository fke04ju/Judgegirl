#include <stdio.h>
#include "evaluate_f.h"
int evaluate_f(int *iptr[], int n, int *index){
    int max = -2147483648;
    for(int i = 0;i<n;i++){
        int fnc = (*iptr[i])*4-(*(iptr[i]+1))*6;
        if(fnc>max){
            max = fnc;
            *index = i;
        }
    }
    return max;
}