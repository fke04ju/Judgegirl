#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left,*right,*parent;
}Node;

void HLHR(Node *root);
void HRHL(Node *root);

Node *construct(Node *root){
	root->data = -1;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	char c;
	int num = 0;
	int checknum = 0;
	while(scanf("%c",&c)!=EOF){
		if(c == '\n'){
			return root;
		}
		while(c >= '0' && c <= '9'){
			num *= 10;
			num += (c - '0');
			scanf("%c",&c);
			checknum = 1;
		}
		if(c == '('){
			Node *new = (Node *)malloc(sizeof(Node));
			root->left = new;
			new->parent = root;
			new->left = NULL;
			new->right = NULL;
			root = root->left;
		}else if(c == ')'){
			if(checknum == 1){
				root->data = num;
				checknum = 0;
				num = 0;
			}else{
				root->data = -1;
			}
			root = root->parent;
		}else if(c == ','){
			if(checknum == 1){
				root->data = num;
				checknum = 0;
				num = 0;
			}else{
				root->data = -1;
			}
			root = root->parent;
			Node *new = (Node *)malloc(sizeof(Node));
			root->right = new;
			new->parent = root;
			new->left = NULL;
			new->right =NULL;
			root = root->right;
		}
	}
	return root;
}

int filldata(Node *root){
	if(root->data == -1){
		root->data = filldata(root->left)+filldata(root->right);
		return root->data;
	}else{
		return root->data;
	}
}

void HLHR(Node *root){
	if(root == NULL){
		return;
	}
	printf("%d\n",root->data);
	HRHL(root->left);
	printf("%d\n",root->data);
	HRHL(root->right);
}

void HRHL(Node *root){
	if(root == NULL){
		return;
	}
	printf("%d\n",root->data);
	HLHR(root->right);
	printf("%d\n",root->data);
	HLHR(root->left);
}

int main(){
	Node *root = (Node *)malloc(sizeof(Node));
	root = construct(root);
	int ok = filldata(root);
	HLHR(root);
}
