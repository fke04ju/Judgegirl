#include <stdio.h>
void loops(int N, int *A, int *B[], int ans[4]){
    int visit[N];
    ans[0] = 0;
    ans[1] = 1000000;
    ans[2] = -2147483648;
    ans[3] = 2147483647;
    for(int i = 0;i<N;i++){
        visit[i] = 0;
    }
    for(int i = 0;i<N;i++){
        if(visit[i] != 0){
            continue;
        }
        int length = 1;
        int loop_first = A[i];
        int now = i;
        int max = loop_first;
        int min = loop_first;
        while(loop_first != *B[now]){
            visit[now]++;
            length ++;
            if(*B[now] > max){
                max = *B[now];
            }
            if(*B[now] < min){
                min = *B[now];
            }
        //    now = where[now];
            now = B[now]-A;
        }
        if(length > ans[0]||(length == ans[0] && max > ans[2])){
            ans[0] = length;
            ans[2] = max;
        }
        if(length < ans[1]||(length == ans[1] && min < ans[3])){
            ans[1] = length;
            ans[3] = min;
        }
    }
    return;
}