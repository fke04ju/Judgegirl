#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
 
int main () {
        int K;
        scanf("%d", &K);
        Node *list[K];
        for (int i = 0; i < K; i++) {
                int N;
                scanf("%d", &N);
                if (N == 0) {
                        list[i] = NULL;
                        continue;
                }
                list[i] = (Node *)malloc(sizeof(Node));
                scanf("%d", &(list[i]->data));
                list[i]->next = NULL;
                Node *previous = list[i];
                for (int j = 1; j < N; j++) {
                        previous->next = (Node *)malloc(sizeof(Node));
                        scanf("%d", &(previous->next->data));
                        previous->next->next = NULL;
                        previous = previous->next;
                }
        }
        Node *result = merge(list, K);
        while (result) {
                printf("%d", result->data);
                result = result->next;
                printf("%c", result ? ' ' : '\n');
        }
        return 0;
}
