#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grading.h"
 
#define MAXN 2147483647
 
int compare(const void *data1,const void *data2){
    int *ptr1 = (int *)data1;
    int *ptr2 = (int *)data2;
    if(ptr1[1] > ptr2[1]){
        return 1;
    }else if(ptr1[1] < ptr2[1]){
        return -1;
    }else{
        if(ptr1[0] > ptr2[0]){
            return 1;
        }else{
            return -1;
        }
    }
}
 
void grading(char answer[10][maxL],Submission* sub,int num_of_submission){
    int score[num_of_submission][3];
    for(int i = 0;i<num_of_submission;i++){
        score[i][0] = sub[i].subID;
        score[i][1] = MAXN;
        score[i][2] = MAXN;
    }
    for(int i = 0;i<num_of_submission;i++){
        int counter = 0;
        for(int j = 0;j<10;j++){
            if(!strcmp(sub[i].outputs[j],answer[j])){
                counter++;
            }
        }
        score[i][1] = sub[i].studentID;
        score[i][2] = counter*10;
    }
    qsort(score,num_of_submission,sizeof(int)*3,compare);
    int max = score[0][2];
    int nowid = score[0][1];
    for(int i = 0;i<num_of_submission;i++){
        if(score[i][1] != MAXN){
            if(nowid == score[i][1]){
                if(max < score[i][2]){
                    max = score[i][2];
                }
            }else{
                printf("Student %d gets %d in this exam.\n",nowid,max);
                nowid = score[i][1];
                max = score[i][2];
            }
            printf("Student %d gets %d with Submission %d.\n",score[i][1],score[i][2],score[i][0]);
        }else{
            break;
        }
    }
    printf("Student %d gets %d in this exam.\n",nowid,max);
    return;
}