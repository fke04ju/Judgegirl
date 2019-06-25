#include <stdio.h>
 
int main(){
  int a,b,c,d,e,s,v;
  scanf("%d\n",&a);
  scanf("%d\n",&b);
  scanf("%d\n",&c);
  scanf("%d\n",&d);
  scanf("%d\n",&e);
  s=2*(a*b+b*c+a*c)+8*d*(a-2*e)+8*d*(b-2*e)+8*d*(c-2*e);
  v=a*b*c-2*d*(a-2*e)*(b-2*e)-2*d*(a-2*e)*(c-2*e)-2*d*(b-2*e)*(c-2*e);
  printf("%d\n%d\n",s,v);
}
