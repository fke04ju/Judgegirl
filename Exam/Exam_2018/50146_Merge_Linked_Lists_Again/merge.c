#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}Node;
Node *merge(Node *list[], int K){
#ifdef ZIGZAG
	int l = 0;
	int end = K;
	int end_list[K];
	for(int i = 0;i<K;i++){
		end_list[i] = 0;
	}
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	Node *current = root;
	while(end != 0){
		if(l%2 == 0){
			for(int i = 0;i<K;i++){
				if(end_list[i] != 1){
					if(list[i] == NULL){
						end --;
						end_list[i] = 1;
					}else{
						Node *new = list[i];
						list[i] = list[i]->next;
						current->next = new;
						current = current->next;
					}
				}
			}
		}else{
			for(int i = K-1;i>=0;i--){
				if(end_list[i] != 1){
					if(list[i] == NULL){
						end --;
						end_list[i] = 1;
					}else{
						Node *new = list[i];
						list[i] = list[i]->next;
						current->next = new;
						current = current->next;
					}
				}
			}
		}
		l++;
	}
	return root->next;
#endif
#ifdef TOPDOWN
	int end = K;
	int end_list[K];
	for(int i = 0;i<K;i++){
		end_list[i] = 0;
	}
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	Node *current = root;
	while(end != 0){
		for(int i = 0;i<K;i++){
			if(end_list[i] != 1){
				if(list[i] == NULL){
					end --;
					end_list[i] = 1;
				}else{
					Node *new = list[i];
					list[i] = list[i]->next;
					current->next = new;
					current = current->next;
				}
			}
		}
	}
	return root->next;
#endif
#ifdef BOTTOMUP
	int end = K;
	int end_list[K];
	for(int i = 0;i<K;i++){
		end_list[i] = 0;
	}
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	Node *current = root;
	while(end != 0){
		for(int i = K-1;i>=0;i--){
			if(end_list[i] != 1){
				if(list[i] == NULL){
					end --;
					end_list[i] = 1;
				}else{
					Node *new = list[i];
					list[i] = list[i]->next;
					current->next = new;
					current = current->next;
				}
			}
		}
	}
	return root->next;
#endif
}
