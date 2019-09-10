#include <stdio.h>

int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int as = a,bs = b,cs = c,ds = d,es = 0,fs = 0,gs = 0;
    es = (a+b+c)*e;
    fs = (c+d)*f;
    gs = e*g;
    int end = g+f;
    int edge = as+bs+cs+ds+es+fs+gs+end;
    int path = a*e*g+b*e*g+c*e*g+c*f+d*f;
    printf("%d\n%d\n",edge,path);
}