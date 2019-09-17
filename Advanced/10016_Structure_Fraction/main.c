#include <stdio.h>
#include "fraction.h"
 
int main() {
    int cmd, x, y, z, w;
    Frac a, b, c;
    scanf("%d", &cmd);
    scanf("%d %d %d %d", &x, &y, &z, &w);
    a = normal(x, y), b = normal(z, w);
    if (cmd == 1) {
        c = add(a, b);
    } else if (cmd == 2) {
        c = subtract(a, b);
    } else if (cmd == 3) {
        c = multipy(a, b);
    } else if (cmd == 4) {
        c = divide(a, b);
    }
    printf("%lld / %lld\n", c.a, c.b);
    return 0;
}