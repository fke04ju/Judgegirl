#include <stdio.h>
#include "card.h"
void shuffle(int *deck[]){
    int array[10000];
    int index=0;
    int i;
    while(deck[index]!=NULL){
        index++;
    }
    if(index%2==0){
        for(i=0;i<index/2;i++){
            array[i*2]=*deck[i];
        }
        for(i=0;i<index-index/2;i++){
            array[i*2+1]=*deck[i+index/2];
        }
    }else{
        for(i=0;i<index/2+1;i++){
            array[i*2]=*deck[i];
        }
        for(i=0;i<index-index/2-1;i++){
            array[i*2+1]=*deck[i+index/2+1];
        }
    }
    for(i=0;i<index;i++){
        *deck[i]=array[i];
    }
}
void print(int *deck[]){
    int i;
    int index=0;
    while(deck[index]!=NULL){
        index++;
    }
  if(index==0){
    printf("");
  }else{
    for(i=0;i<index-1;i++){
        printf("%d ",*deck[i]);
    }
  printf("%d",*deck[index-1]);
  }
}