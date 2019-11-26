#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grading.h"
 
#define maxL 1000
 
int main(){
    char answer[10][maxL];
    int  num_of_submission;
    Submission* sub;
 
    for(int i=0;i<10;i++){
        scanf("%s",answer[i]);
    }
 
    scanf("%d",&num_of_submission);
 
    sub=(Submission*)malloc(num_of_submission*sizeof(Submission)); 
    for(int i=0;i<num_of_submission;i++){
        scanf("%d %d",&sub[i].subID,&sub[i].studentID);
        for(int j=0;j<10;j++){
            scanf("%s",sub[i].outputs[j]);
        }
    }
    grading(answer,sub,num_of_submission);
}