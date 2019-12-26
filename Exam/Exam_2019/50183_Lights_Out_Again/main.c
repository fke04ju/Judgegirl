#include <stdio.h>
#include <stdlib.h>
#include "lights.h"

int output[20] = {};
int stack[20] = {};
int check[20] = {};
int min = 2147483647;
 
void rec(Lights *l,int idx,int now,int N){
    if(idx == N*N || now == N*N){
        return;
    }
    if(numOfLights(l,N) == 0){
        if(idx < min){
            min = idx;
            for(int i = 0;i<idx;i++){
                output[i] = stack[i];
            }
        }
        stack[idx-1] = 0;
        return;
    }
    for(int i = now;i<N*N;i++){
        if(check[i] == 0){
            check[i] = 1;
            stack[idx] = i;
            flip(l,i,N);
            rec(l,idx+1,i,N);
            flip(l,i,N);
            check[i] = 0;
        }
    }
}
 
int main(){
    Lights l;
    init(&l);
    int n;
    int a;
    scanf("%d",&n);
    for(int i = 0;i<20;i++){
        output[i] = 2147483647;
    }
    while(scanf("%d",&a)!=EOF){
        flip(&l,a,n);
    }
    rec(&l,0,0,n);
    for(int i = 0;i<min;i++){
        printf("%d%c",output[i],(i<min-1)?' ':'\n');
    }
}