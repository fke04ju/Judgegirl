#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void splitAndMap(char*** ptr, char* str){
    int n = 0;
    while(ptr[n] != NULL){
        n++;
    }
    int number[n];
    int ptrnum[n];
    for(int i = 0;i<n;i++){
        number[i] = 0;
        ptrnum[i] = 0;
    }
    str = strtok(str,"*");
    while(str != NULL){
        int idx = 0;
        int min = 2147483647;
        for(int i = 0;i<n;i++){
            if(min > number[i]){
                min = number[i];
                idx = i;
            }
        }
        number[idx] += strlen(str);
        ptr[idx][ptrnum[idx]] = str;
        ptrnum[idx] ++;
        str = strtok(NULL,"*");
    }
    for(int i = 0;i<n;i++){
        ptr[i][ptrnum[i]] = NULL;
    }
    return;
}