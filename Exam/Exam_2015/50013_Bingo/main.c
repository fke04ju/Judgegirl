#include <stdio.h>
#include "bingo.h"
int main(void)
{
    unsigned long long int board;
    int res = 0, rowColumn = 0;
    scanf("%llu", &board);
    res = bingo(&board, &rowColumn);
    if(res == 0) printf("no\n");
    else printf("%d %d\n", res, rowColumn);
    return 0;
}