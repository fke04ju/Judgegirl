#include <stdio.h>
#include <assert.h>
#include "snake.h"
 
void snake(const int *ptr_array[100][100], int m){
  const int *temp[m*m];
  for(int i = 0;i<m;i++){
    for (int j = 0;j<m;j++){
      temp[i*m+j] = ptr_array[i][j];
    }
  }
  for(int i = 0;i<m*m-1;i++){
    for(int j = 0;j<m*m-i-1;j++){
      if(*temp[j]>*temp[j+1]){
        const int *tmp = temp[j+1];
        temp[j+1] = temp[j];
        temp[j] = tmp;
      }
    }
  }
  int count = 0;
  for(int i = 0;i<m;i++){
    if(i%2 == 0){
      for(int j = 0;j<m;j++){
        ptr_array[i][j] = temp[count];
        count++;
      }
    }else{
      for(int j = m-1;j>=0;j--){
        ptr_array[i][j] = temp[count];
        count++;
      }
    }
  }
  return;
}