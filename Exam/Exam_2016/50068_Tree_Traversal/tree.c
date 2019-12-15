#include "tree.h"
#include <stdio.h>

void traversal(Node *root, int N, int command[]){
    Node *ptr[1000];
    int index = 0;
    ptr[0] = root;
    for(int i = 0;i<N;i++){
        if(command[i] == 0){
            printf("%d\n",ptr[index]->label);
            return;
        }else if(command[i] == 1){
            printf("%d\n",ptr[index]->label);
        }else if(command[i] == 2){
            if(index > 0){
                index--;
            }else{
                printf("%d\n",ptr[index]->label);
                return;
            }
        }else if(command[i] == 3){
            if(ptr[index]->left != NULL){
                ptr[index+1] = ptr[index]->left;
                index++;
            }else{
                printf("%d\n",ptr[index]->label);
                return;
            }
        }else if(command[i] == 4){
            if(ptr[index]->right != NULL){
                ptr[index+1] = ptr[index]->right;
                index++;
            }else{
                printf("%d\n",ptr[index]->label);
                return;
            }
        }else if(command[i] == 5){
            if(index > 0 && ptr[index-1]->left != NULL && ptr[index-1]->right != NULL){
                if(ptr[index] == ptr[index-1]->left){
                    ptr[index] = ptr[index-1]->right;
                }else{
                    ptr[index] = ptr[index-1]->left;
                }
            }else{
                printf("%d\n",ptr[index]->label);
                return;
            }   
        }
    }
}