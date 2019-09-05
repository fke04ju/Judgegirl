#include <stdio.h>
#include "setmatrix.h"
 
void processSetMatrix(int ***ptr) {
    int a = 0;
    while(ptr[a] != NULL){
        int b = 0;
        while(ptr[a][b] != NULL){
            int c = 0;
            while(ptr[a][b][c] != 0){
                printf("%d ",ptr[a][b][c]);
                c++;
            }
            b++;
        }
        a++;
    }
    return;
}