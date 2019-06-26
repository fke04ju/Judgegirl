#include <stdio.h>
int main(){
  int i,a,b,c;
  scanf("%d",&i);
  a=i/100;
  b=(i%100)/10;
  c=i%10;
  printf("%d\n%d\n%d",a,b,c);
}
