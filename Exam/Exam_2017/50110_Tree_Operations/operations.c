#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

Node *FlipTree(Node *root){
    Node *new = (Node *)malloc(sizeof(Node));
    if(root->left == NULL && root->right == NULL){
        new->n = root->n;
        new->left = new->right = NULL;
        return new;
    }else if(root->left == NULL){
        new->n = root->n;
        new->right = NULL;
        new->left = FlipTree(root->right);
        return new;
    }else if(root->right == NULL){
        new->n = root->n;
        new->left= NULL;
        new->right = FlipTree(root->left);
        return new;
    }else{
        new->n = root->n;
        new->left = root->right;
        new->right = root->left;
        new->left = FlipTree(root->right);
        new->right = FlipTree(root->left);
        return new;
    }
}

int isIdentical(Node *tree1, Node *tree2){
    if(tree1 == NULL && tree2 == NULL){
        return 1;
    }else if(tree1 == NULL || tree2 == NULL){
        return 0;
    }else{
        if(tree1->n != tree2->n){
            return 0;
        }else{
            return isIdentical(tree1->left,tree2->left)&isIdentical(tree1->right,tree2->right);
        }
    }
}

int num_leaf;
int sum_depth;

void find_depth(Node *root,int depth){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        sum_depth += depth;
        num_leaf++;
        return;
    }
    find_depth(root->left,depth+1);
    find_depth(root->right,depth+1);
    return;
}

void depthAvg(Node *root){
    num_leaf = 0;
    sum_depth = 0;
    find_depth(root,0);
    printf("%d/%d\n",sum_depth,num_leaf);
}