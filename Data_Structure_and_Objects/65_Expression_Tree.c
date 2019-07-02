#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
	char operator[33];
	struct Node *left,*right;
}Node;

Node *construct(Node *root){
	root = (Node *)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	char op[33];
	scanf("%s",op);
	if(op[0] == '('){
		scanf("%s",op);
		strcpy(root->operator,op);
		root->left = construct(root->left);
		root->right = construct(root->right);
		scanf("%s",op);
	}else{
		strcpy(root->operator,op);
	}
	return root;
}

char table_var[50][33];
int table_const[50];
int n = 0;

int calculate(Node *root){
	if(root->operator[0] == '+'){
		return calculate(root->left)+calculate(root->right);
	}else if(root->operator[0] == '-'){
		return calculate(root->left)-calculate(root->right);
	}else if(root->operator[0] == '*'){
		return calculate(root->left)*calculate(root->right);
	}else if(root->operator[0] == '/'){
		return calculate(root->left)/calculate(root->right);
	}else{
		if(isdigit(root->operator[0])){
			return atoi(root->operator);
		}else{
			for(int i = 0;i<n;i++){
				if(!strcmp(root->operator,table_var[i])){
					return table_const[i];
				}
			}
		}
	}
}

int main(){
	Node *root = (Node *)malloc(sizeof(Node));
	root = construct(root);
	char op[3];
	while(scanf("%s%s%d",table_var[n],op,&table_const[n])!=EOF){
		n++;
	}
	int total = calculate(root);
	printf("%d\n",total);
}
