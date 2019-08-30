#include <stdio.h>
 
int main() {
    int a,b;
    int top=-10001;
    int down=10001;
    int left=10001;
    int right=-10001;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>=top){
            top=a;
        }
        if(a<=down){
            down=a;
        }
        if(left>=b){
            left=b;
        }
        if(right<=b){
            right=b;
        }
//        printf("%d %d\n",a,b);
    }
//    printf("%d %d %d %d\n",top,down,left,right);
    int i,j;
    i=top-down;
    j=right-left;
    if(top==-10001 || down==10001 || left==10001 || right==-10001){
        printf("0");
    }else{
        printf("%d",i*j);
    }
}