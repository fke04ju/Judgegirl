#include <stdio.h>
#include "matrixOperations.h"
#include<stdint.h>
 
int main() {
   uint64_t num;
   char operation;
   scanf("%lu", &num);
   while (1) {
       scanf("%c", &operation);
       if (operation == 'p') {
           printMatrix(&num);
           break;
       } else if (operation == 'r')
           rotateMatrix(&num);
       else if (operation == 't')
           transposeMatrix(&num);
   }
   return 0;
}