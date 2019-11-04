#include <stdio.h>
#include <stdlib.h>
 
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
    int number = 0;
    int counter = 0;
    while((ptrArray[counter] == NULL && ptrArray[counter+1] == NULL) == 0){
        counter++;
    }
    int cnt = 0;
    while(cnt < counter){
        int start = cnt;
        while(ptrArray[cnt] != NULL){
            int flag = 0;
            for(int i = start;i<cnt && flag == 0;i++){
                if(ptrArray[cnt] == ptrArray[i]){
                    flag = 1;
                }
            }
            if(flag == 0){
                answer[number] += *ptrArray[cnt];
            }
            cnt++;
        }
        cnt++;
        number++;
    }
    *numberOfBlocks = number;
    return;
}