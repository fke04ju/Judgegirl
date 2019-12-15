#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *myconstruct(Node *root,int idx,int array[],int n){
    if(idx >= n){
        return NULL;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->label = array[idx];
    tmp->left = tmp->right = NULL;
    root = tmp;
    root->left = myconstruct(root->left,idx*2+1,array,n);
    root->right = myconstruct(root->right,idx*2+2,array,n);
    return root;
}

Node *construct(int array[], int n){
    Node *root;
    root = myconstruct(root,0,array,n);
}