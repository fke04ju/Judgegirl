#include <stdio.h>
#include <stdlib.h>
#include "lights.h"
int dx[5] = {-1,0,1,0,0};
int dy[5] = {0,1,0,-1,0};
void init(Lights *l){
    for(int i = 0;i<25;i++){
        l->arr[i] = 0;
    }
    l->on = 0;
    return;
}
int numOfLights(Lights *l,int N){
    return l->on;
}
void flip(Lights *l,int i,int N){
    Lights *tmp = l;
    int x = i/N;
    int y = i%N;
    for(int k = 0;k<5;k++){
        int newx = x+dx[k];
        int newy = y+dy[k];
        if(newx >= 0 && newx < N && newy >= 0 && newy < N){
            if(tmp->arr[(newx)*N+newy] == 0){
                tmp->arr[(newx)*N+newy] = 1;
                tmp->on++;
            }else{
                tmp->arr[(newx)*N+newy] = 0;
                tmp->on--;
            }
            //printf("in\n");
        }
    }
    return;
}
void printLights(Lights *l,int N){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            printf("%d%c",l->arr[i*N+j],(j<N-1)?' ':'\n');
        }
    }
    return;
}