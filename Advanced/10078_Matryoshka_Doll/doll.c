#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doll.h"

Doll *newDoll(char top, char bottom){
    Doll *new = (Doll *)malloc(sizeof(Doll));
    new->top = top;
    new->bottom = bottom;
    new->interior = NULL;
    return new;
}

void package(Doll *outer, Doll *inter){
    outer->interior = inter;
    return;
}

const char* doll_c_str(Doll *doll){
    int first = 0;
    int cnt = 0;
    Doll *tmp = doll;
    while(tmp != NULL){
        cnt++;
        tmp = tmp->interior;
    }
    char *ans;
    ans = malloc(sizeof(char)*(cnt*2+1));
    int last = cnt*2-1;
    Doll *tmp2 = doll;
    while(tmp2 != NULL){
        ans[first] = tmp2->top;
        ans[last] = tmp2->bottom;
        first++;
        last--;
        tmp2 = tmp2->interior;
    }
    ans[cnt*2] = '\0';
    return ans;
}
