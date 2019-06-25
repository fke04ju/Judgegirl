#include <stdio.h>
int main(){
  int h,w,d,s,v;
  scanf("%d",&h);
  scanf("%d",&w);
  scanf("%d",&d);
  s=2*(h*w+w*d+h*d);
  v=h*w*d;
  printf("%d\n",s);
  printf("%d",v);
}
