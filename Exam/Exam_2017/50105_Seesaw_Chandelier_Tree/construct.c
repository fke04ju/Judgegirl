#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

Node *myconstruct(int T[],int left,int right){
    Node *root = (Node *)malloc(sizeof(Node));
    if(right-left < 2){
        root->value = T[right];
        root->left = root->right = NULL;
        Node *tmp = root;
        for(int i = right-1;i>= left;i--){
            Node *new = (Node *)malloc(sizeof(Node));
            new->value = T[i];
            new->left = new->right = NULL;
            tmp->left = new;
            tmp = tmp->left;
        }
        return root;
    }
    long long sum_left = 0;
    long long sum_right = 0;
    int found = 0;
    for(int i = left;i<=right;i++){
        sum_left = 0;
        sum_right = 0;
        int extra = 1;
        if(i-1 >= left){
            for(int j = i-1;j>=left;j--){
                sum_left += (long long)(T[j]*extra);
                extra++;
            }
        }
        extra = 1;
        if(i+1 <= right){
            for(int j = i+1;j<=right;j++){
                sum_right += (long long)(T[j]*extra);
                extra++;
            }
        }
        if(sum_left == sum_right){
            found = 1;
            root->value = T[i];
            root->left = root->right = NULL;
            if(i-1 >= left){
                root->left = myconstruct(T,left,i-1);
            }
            if(i+1 <= right){
                root->right = myconstruct(T,i+1,right);
            }
            return root;
        }
    }
    if(found == 0){
        root->value = T[right];
        root->left = root->right = NULL;
        Node *tmp = root;
        for(int i = right-1;i>= left;i--){
            Node *new = (Node *)malloc(sizeof(Node));
            new->value = T[i];
            new->left = new->right = NULL;
            tmp->left = new;
            tmp = tmp->left;
        }
        return root;
    }
}

Node *ConstructTree(int T[], int N){
    return myconstruct(T,0,N-1);
}