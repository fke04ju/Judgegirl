#include "max.h"
int max(int array[5][5]) {
    int m=-2147483648;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(m<array[i][j]){
        m=array[i][j];
      }
    }
  }
  return m;
}