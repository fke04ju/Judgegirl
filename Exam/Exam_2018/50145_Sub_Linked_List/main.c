#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sub.h"
 
Node* insert(Node* root, char c)
{
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->c = c;
        root->next = NULL;
        return root;
    }
    root->next = insert(root->next, c);
    return root;
}
int main(int argc, char const *argv[])
{
    char tmp = '\n';
    int N, M, i, act;
    Node *text = NULL, *pattern = NULL, *cur = NULL;
 
    scanf("%d%d", &act, &N);
    while(isspace(tmp)) scanf("%c", &tmp);
    text = insert(text, tmp);
    cur = text;
    for(i = 0; i < N-1; i++){
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }
 
    scanf("%d", &M);
    tmp = '\n';
    while(isspace(tmp)) scanf("%c", &tmp);
    pattern = insert(pattern, tmp);
    cur = pattern;
    for(i = 0; i < M-1; i++){
        scanf("%c", &tmp);
        cur->next = insert(cur->next, tmp);
        cur = cur->next;
    }
    if (!act)
        substring(text, pattern);
    else
        subsequence(text, pattern);
    return 0;
}
