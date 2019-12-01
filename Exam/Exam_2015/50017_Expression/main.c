#include <stdio.h>
#include <string.h>
#include "expression.h"
 
char buf[1<<20];
int main() {
    while (scanf("%s", buf) == 1) {
        int ret = expression(buf);
        printf("%d\n", ret);
    }
    return 0;
}