#include <stdio.h>
#include <stdlib.h>
typedef struct _lights{
    int arr[25];
    int on;
}Lights;
 
void init(Lights *l);
int numOfLights(Lights *l,int N);
void flip(Lights *l,int i,int N);
void printLights(Lights *l,int N);