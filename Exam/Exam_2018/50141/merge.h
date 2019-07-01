#ifndef MERGE_H
#define MERGE_H
typedef struct node {
    int data;
    struct node *next;
}Node;
Node *merge(Node *list[], int K);
#endif
