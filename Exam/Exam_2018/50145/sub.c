#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sub.h"

/*
typedef struct Node{
    char c;
    struct Node *next;
}Node;
*/

void substring(Node* text, Node* pattern){
	int value = 0;
	int index = 0;
	int check = 0;
	int ifcorr = 0;
	int substr_index;
	Node *substr_text = (Node *)malloc(sizeof(Node));
	Node *substr_patt = (Node *)malloc(sizeof(Node));
	while(check == 0){
		while(text->c != pattern->c){
			text = text->next;
			index ++;
		}
		substr_index = index;
		substr_patt = pattern;
		substr_text = text;
		while(substr_patt != NULL){
			if(substr_text->c == substr_patt->c){
				ifcorr ++;
				value += substr_index;
				substr_index++;
				substr_text = substr_text->next;
				substr_patt = substr_patt->next;
			}else{
				break;
			}
		}
		if(substr_patt == NULL){
			printf("%d\n",value);
			check = 1;
		}else{
			text = text->next;
			index++;
			value = 0;
			ifcorr = 0;
		}
	}
	return;
}
void subsequence(Node* text, Node* pattern){
	int value = 0;
	int index = 0;
	int check = 0;
	while(check == 0){
		while(text->c != pattern->c){
			text = text->next;
			index ++;
		}
		value += index;
		if(pattern->next == NULL){
			printf("%d\n",value);
			check = 1;
		}else{
			pattern = pattern->next;
			text = text->next;
			index++;
		}
	}
	return;
}
