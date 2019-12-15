#include <stdio.h>
#include <stdlib.h>
#include "subtree.h"

int n = 0;

int dfs(Node *root,int label[],int k){
    if(root == NULL){
        return 0;
    }
    int l = dfs(root->left,label,k);
    int r = dfs(root->right,label,k);
    if(l && r && root->label != k){
        label[n++] = root->label;
    }
    int stat = 0;
    if(l){
        stat = 1;
    }
    if(r){
        stat = 1;
    }
    if(root->label == k){
        stat = 1;
    }
    return stat;
}

int getNode(Node *root, int label[], int k){
    n = 0;
    dfs(root,label,k);
    return n;
}
