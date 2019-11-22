#include "subset.h"
 
int subset(int numbers[], int n, int K, int S){
    if(K == 0 && S == 0){
        return 1;
    }
    if(K < 0 || n == 0 || S < 0 || S > n){
        return 0;
    }
    return subset(numbers,n-1,K-numbers[n-1],S-1) || subset(numbers,n-1,K,S);
}