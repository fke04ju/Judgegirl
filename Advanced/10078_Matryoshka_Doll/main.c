#include "doll.h"
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    Doll *dolls[3];
    dolls[0] = newDoll('<', '~');
    dolls[1] = newDoll('(', ')');
    dolls[2] = newDoll('@', '>');
    package(dolls[1], dolls[2]);
    package(dolls[0], dolls[1]);
    printf("%s\n", doll_c_str(dolls[0]));
    return 0;
}