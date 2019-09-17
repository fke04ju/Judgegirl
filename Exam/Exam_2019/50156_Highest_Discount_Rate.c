#include <stdio.h>

int main(){
    int a,b,v,w,x,y,z;
    scanf("%d%d%d%d%d%d%d",&a,&b,&v,&w,&x,&y,&z);
    int max_d = 0,max_p = 1;
    int p1 = 1,p21 = a,p22 = a+1,p31 = b,p32 = b+1,p33 = b+2;
    int d1 = 0;
    int d21,d22,d31,d32,d33;
    if(a % 2 == 0){
        d21 = w;
        d22 = v;
    }else{
        d21 = v;
        d22 = w;
    }
    if(b % 3 == 0){
        d31 = x;
        d32 = y;
        d33 = z;
    }else if(b % 3 == 1){
        d33 = x;
        d31 = y;
        d32 = z;
    }else{
        d32 = x;
        d33 = y;
        d31 = z;
    }
    if(d1*max_p > p1*max_d){
        max_p = p1;
        max_d = d1;
    }
    if(d21*max_p > p21*max_d){
        max_p = p21;
        max_d = d21;
    }
    if(d22*max_p > p22*max_d){
        max_p = p22;
        max_d = d22;
    }
    if(d31*max_p > p31*max_d){
        max_p = p31;
        max_d = d31;
    }
    if(d32*max_p > p32*max_d){
        max_p = p32;
        max_d = d32;
    }
    if(d33*max_p > p33*max_d){
        max_p = p33;
        max_d = d33;
    }
    printf("%d",max_p);
}