#include <stdio.h>
int main(){
    int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,sec;
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&sec);
    for(int i = 0;i<sec;i++){
        x1+=dx1;x2+=dx2;y1+=dy1;y2+=dy2;
        if(x1 == x2 && y1 == y2){
            int tmp1 = dx1;
            dx1 = dx2;
            dx2 = tmp1;
            int tmp2 = dy1;
            dy1 = dy2;
            dy2 = tmp2;
        }
        if(x1 == 1 || x1 == X){
            dx1 *= -1;
        }
        if(y1 == 1 || y1 == Y){
            dy1 *= -1;
        }
        if(x2 == 1 || x2 == X){
            dx2 *= -1;
        }
        if(y2 == 1 || y2 == Y){
            dy2 *= -1;
        }
    }
    printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);
}
