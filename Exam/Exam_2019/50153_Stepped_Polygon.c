#include <stdio.h>
 
int main(){
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int len = a+c+e;
    int wid = b+d+f;
    int total = len*wid;
    int ans = total-(b*c)-(d*e)-(b*e);
    int around = (len+wid)*2;
    printf("%d\n",around);
    printf("%d\n",ans);
}