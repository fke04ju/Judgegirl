#include <stdio.h>
#include <stdlib.h>
int main(){
    int x0,y0,z0;
    scanf("%d%d%d",&x0,&y0,&z0);
    int mx,my,mz;
    int bx,by,bz;
    scanf("%d%d%d%d%d%d",&mx,&my,&mz,&bx,&by,&bz);
    int step;
    int countstep = 1;
    int explosion = 0;
    int blackhole_disappear = 0;
    int N;
    int dist_mine = abs(mx-x0)+abs(my-y0)+abs(mz-z0);
    if(dist_mine < 10){
        explosion = 1;
    }
    if(explosion == 0){
        int dist_bh = abs(bx-x0)+abs(by-y0)+abs(bz-z0);
        if(dist_bh < 10){
            blackhole_disappear = 1;
            x0 = bx;
            y0 = by;
            z0 = bz;
        }
    }
    scanf("%d",&N);
    while(scanf("%d",&step) != EOF && explosion == 0){
        if(explosion == 0){
            if(step == 1){
                x0++;
            }else if(step == 2){
                x0--;
            }else if(step == 3){
                y0++;
            }else if(step == 4){
                y0--;
            }else if(step == 5){
                z0++;
            }else if(step == 6){
                z0--;
            }
        }
        dist_mine = abs(mx-x0)+abs(my-y0)+abs(mz-z0);
        if(dist_mine < 10){
            explosion = 1;
        }
        if(blackhole_disappear == 0 && explosion == 0){
            int dist_bh = abs(bx-x0)+abs(by-y0)+abs(bz-z0);
            if(dist_bh < 10){
                blackhole_disappear = 1;
                x0 = bx;
                y0 = by;
                z0 = bz;
            }
        }
        if(countstep%5 == 0 && explosion == 0){
            printf("%d %d %d\n",x0,y0,z0);
        }
        countstep++;
    }
}