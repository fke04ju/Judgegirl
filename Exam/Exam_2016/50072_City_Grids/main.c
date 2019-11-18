#include "City_Grid.h"
#include <stdio.h>
#include <stdlib.h>
 
City* newNode(int label, City *E, City *N) {
    City *u = (City *) malloc(sizeof(City));
    u->label = label, u->east = E, u->north = N;
    return u;
}
 
int main() {
    City *capital = newNode(0, NULL, NULL);
    capital->east = newNode(1, newNode(3, NULL, NULL), NULL);
    capital->north = newNode(2, NULL, newNode(5, NULL, NULL));
    capital->east->north = capital->north->east = newNode(4, NULL, NULL);
 
    City *temp = capital->east->north;
    temp->east = newNode(6, NULL, NULL);
    temp->north = newNode(7, NULL, NULL);
    temp->east->north = temp->north->east = newNode(8, NULL, NULL);
 
    printf("%d\n", City_Grid(capital));
    return 0;
}