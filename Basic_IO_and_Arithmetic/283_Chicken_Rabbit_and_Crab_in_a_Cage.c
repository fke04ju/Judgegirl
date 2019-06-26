#include <stdio.h>
int main(){
  int a,b,c,s,f,t;
  scanf("%d\n%d\n%d",&s,&f,&t);
  c=s-t;
  b=(f-8*c-2*t)/2;
  a=t-b;
  printf("%d\n%d\n%d\n",a,b,c);
}
