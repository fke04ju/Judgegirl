#include <stdio.h>
#include <stdlib.h>

int dir_func(int a,int b,int x,int y){
    return abs((a*x+b*y))%4;
}

int gold(int x,int y,int c,int d,int e){
    return abs(c*x+d*y)%e;
}

int main(){
    int a,b,c,d,e,p,q,r,s,x,y,F;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&p,&q,&r,&s,&x,&y,&F);
    int total_gold = gold(x,y,c,d,e);
    while(F--){
        int dir = dir_func(a,b,x,y);
        if(dir == 0){
            y++;
        }else if(dir == 1){
            x++;
        }else if(dir == 2){
            y--;
        }else{
            x--;
        }
        int th = 0;
        if(p < 1000 && q < 1000 && r < 1000 && s < 1000){
            th = 1;
        }
        if(x == p && y == q && th == 1){
            x = r;
            y = s;
        }else if(x == r && y == s && th == 1){
            x = p;
            y = q;
        }else{
            total_gold += gold(x,y,c,d,e);
        }
    }
    printf("%d\n%d %d\n",total_gold,x,y);
}