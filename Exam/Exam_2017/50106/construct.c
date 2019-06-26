#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
#ifndef CONSTRUCT
#define CONSTRUCT
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
	Node *root = (Node *)malloc(sizeof(Node));
	strcpy(root->name,name[0]);
	root->height = height[0];
	root->weight = weight[0];
	root->left = NULL;
	root->right = NULL;
#ifdef HEIGHT
	for(int i = 1;i<N;i++){
		Node *current = root;
		Node *prev = root;
		while(current!=NULL){
			if(height[i] < current->height){
				prev = current;
				current = current->left;
			}else{
				prev = current;
				current = current->right;
			}
		}
		Node *new = (Node *)malloc(sizeof(Node));
		if(prev->height > height[i]){
			prev->left = new;
		}else{
			prev->right = new;
		}
		strcpy(new->name,name[i]);
		new->height = height[i];
		new->weight = weight[i];
		new->left = NULL;
		new->right = NULL;
//		printf("%s %d\n",name[i],i);	
	}
	return root;
#endif
#ifdef WEIGHT
	for(int i = 1;i<N;i++){
		Node *current = root;
		Node *prev = root;
		while(current!=NULL){
			if(weight[i] < current->weight){
				prev = current;
				current = current->left;
			}else{
				prev = current;
				current = current->right;
			}
		}
		Node *new = (Node *)malloc(sizeof(Node));
		if(prev->weight > weight[i]){
			prev->left = new;
		}else{
			prev->right = new;
		}
		strcpy(new->name,name[i]);
		new->height = height[i];
		new->weight = weight[i];
		new->left = NULL;
		new->right = NULL;
//		printf("%s %d\n",name[i],i);	
	}
	return root;
#endif
}
#endif
