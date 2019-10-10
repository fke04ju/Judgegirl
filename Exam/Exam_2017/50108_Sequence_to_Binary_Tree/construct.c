#include <stdio.h>
#include <stdlib.h>
#include"construct.h"
int k;
#ifdef MAXLENGTH
    int k = MAXLENGTH;
#endif
int newarr[17000];

int cmp(const void *data1,const void *data2){
    int *ptr1 = (int *)data1;
    int *ptr2 = (int *)data2;
    if(*ptr1 > *ptr2){
        return 1;
    }else if(*ptr1 < *ptr2){
        return -1;
    }else{
        return 0;
    }
}

Node *myconstruct(int arr[],int left,int right){
    for(int i = 0;i<k;i++){
        newarr[i] = 0;
    }
    if(left > right){
        return NULL;
    }
    Node *root = (Node *)malloc(sizeof(Node));
    if(right-left+1 < k){
        root->value = arr[right];
        root->left = root->right = NULL;
        Node *tmp = root;
        for(int i = right-1;i>=left;i--){
            Node *new = (Node *)malloc(sizeof(Node));
            new->value = arr[i];
            new->left = new->right = NULL;
            tmp->left = new;
            tmp = tmp->left;
        }
        return root;
    }
    for(int i = left;i<left+k;i++){
        newarr[i-left] = arr[i];
    }
    qsort(newarr,k,sizeof(int),cmp);
    for(int i = left+k;i<=right;i++){
        if(newarr[0] < arr[i]){
            newarr[0] = arr[i];
            int cnt = 1;
            while(newarr[cnt] < newarr[cnt-1] && cnt < k){
                int tmp = newarr[cnt];
                newarr[cnt] = newarr[cnt-1];
                newarr[cnt-1] = tmp;
                cnt++;
            }
        }
    }
    int idx = 0;
    for(int i = left;i<=right;i++){
        if(newarr[0] == arr[i]){
            idx = i;
        }
    }
    root->value = newarr[0];
    root->left = root->right = NULL;
    root->left = myconstruct(arr,left,idx-1);
    root->right = myconstruct(arr,idx+1,right);
    return root;
}

Node* ConstructTree(int sequence[], int N){
    Node *root = myconstruct(sequence,0,N-1);
    return root;
}