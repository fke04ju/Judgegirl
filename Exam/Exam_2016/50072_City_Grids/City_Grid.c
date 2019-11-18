#include "City_Grid.h"
#include <stdio.h>
#include <stdlib.h>
int count = 0;
int array[10000] = {};

void recur(City *capital){
    if(capital == NULL){
        return;
    }
    if(array[capital->label] == 1){
        return;
    }
    if(capital->east != NULL && capital->north != NULL){
        if(capital->east->north != NULL && capital->north->east != NULL){
            count ++;
            array[capital->label] = 1;
        }
        recur(capital->east);
        recur(capital->north);
    }else if(capital->north != NULL){
        recur(capital->north);
    }else if(capital->east != NULL){
        recur(capital->east);
    }
    return;
}

int City_Grid(City *capital){
    count = 0;
    for(int i = 0;i<10000;i++){
        array[i] = 0;
    }
    recur(capital);
    return count;
}