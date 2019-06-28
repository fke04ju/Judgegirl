#include <stdio.h>
int main(){
    int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);
    int explode = 0,time = 0;
    while(explode == 0 && (f1>0 || f2>0)){
        if(f1>0){
            if(time%(n1+e1)<n1){
                if(y1+1 == n){
                    y1 = 0;
                }else{
                    y1 += 1;
                }
            }else{
                if(x1+1 == m){
                    x1 = 0;
                }else{
                    x1 += 1;
                }
            }
            f1--;
        }
        if(f2>0){
            if(time%(n2+e2)<e2){
                if(x2+1 == m){
                    x2 = 0;
                }else{
                    x2 += 1;
                }
            }else{
                if(y2+1 == n){
                    y2 = 0;
                }else{
                    y2 += 1;
                }
            }
            f2--;
        }
 
        if(x1 == x2 && y1 == y2){
            printf("robots explode at time %d\n",time+1);
            explode = 1;
        }
        time ++;
    }
    if(explode == 0){
        printf("robots will not explode\n");
    }
}
