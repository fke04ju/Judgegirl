#include <stdio.h>
#include <math.h>
 
int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int fx,fy,fz;
    int i = -100000,check = 1;
    while(check == 1){
        if(i == 0){
            i++;
        }else{
            if(z == 0){
                fx = 0;check = 0;
            }else if(z%i == 0){
                if((-1*i*i*i+x*i*i-y*i+z) == 0){
                    fx = i;check = 0;
                }
            }
            i++;
        }
    }
//    printf("%d",fx);
    int h;
    if(fx == 0){
        h = y;
    }else{
        h = z/fx;
    }
    int g = x-fx;
//    printf("%d %d\n",g,h);
    if(y == 0 && z == 0){
        fy = x;
        fz = y;
    }else{
        fy = -((-1*g)+sqrt(g*g-4*h))/2;
        fz = -((-1*g)-sqrt(g*g-4*h))/2;
    }
 
    if(fx>fy){
        int k = fy;
        fy = fx;
        fx = k;
    }
    if(fy>fz){
        int k = fz;
        fz = fy;
        fy = k;
    }
    if(fx>fz){
        int k = fx;
        fx = fz;
        fz = k;
    }
    printf("%d %d %d",fx,fy,fz);
    return 0;
}
