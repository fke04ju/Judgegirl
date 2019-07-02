#include <stdio.h>
 
int gcd(int up, int down) {
    int r;
        while(up%down != 0){
            r = down;
            down = up%down;
            up = r;
        }
    return down;
}
 
int main() {
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int x,y;
    if(a >= 0){
        x = a*c+b;
    }else{
        x = a*c-b;
    }
    if(e >= 0){
        y = e*g+f;
    }else{
        y = e*g-f;
    }
    int up,down;
    int top,under;
    if(d == 0){
            down = c*g;
            up = x*g + y*c;
            top = up/gcd(up,down);
            under = down/gcd(up,down);
            if(top%under == 0){
                printf("%d\n0\n1",top/under);
            }
            else if(up/down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),-under);
            }else if(up < 0 && down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),under);
            }else {
                printf("%d\n%d\n%d",top/under,top%under,under);
            }
        }else if(d == 1){
            down = c*g;
            up = x*g-y*c;
            top = up/gcd(up,down);
            under = down/gcd(up,down);
            if(top % under == 0){
                printf("%d\n0\n1",top/under);
            }
            else if(up / down < 0){
                printf("%d\n%d\n%d",top/under,-(top%under),under);
            }else if(up < 0 && down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),under);
            }else {
                printf("%d\n%d\n%d",top/under,top%under,under);
            }
        }else if(d == 2){
            down = c*g;
            up = x*y;
            top = up/gcd(up,down);
            under = down/gcd(up,down);
            if(top % under == 0){
                printf("%d\n0\n1",top/under);
            }
            else if(up / down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),-under);
            }else if(up < 0 && down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),under);
            }else {
                printf("%d\n%d\n%d",top/under,top%under,under);
            }
        }else{
            down = c*y;
            up = x*g;
            top = up/gcd(up,down);
            under = down/gcd(up,down);
            if(top % under == 0){
                printf("%d\n0\n1",top/under);
            }
            else if(up / down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),-under);
            }else if(up < 0 && down < 0){
                printf("%d\n%d\n%d",top/under,(top%under),under);
            }else {
                printf("%d\n%d\n%d",top/under,top%under,under);
            }
        }
}
