#include <stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int t = 2*m*m;
    int train[20][20] = {};
    int rej;
    int w[20][20];
    for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++){
            w[i][j] = 1;
        }
    }
    int c;
    for(int i = 0;i<n;i++){
        int h = 0;
        scanf("%d",&c);
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                scanf("%d",&train[j][k]);
                h+=(train[j][k]*w[j][k]);
            }
        }
        if(h < t){
            rej = 0;
        }else{
            rej = 1;
        }
        if(rej != c){
            if(c == 1){
                for(int j = 0;j<m;j++){
                    for(int k = 0;k<m;k++){
                        if(train[j][k] == 1){
                            w[j][k] *= 2;
                        }
                    }
                }
            }else{
                for(int j = 0;j<m;j++){
                    for(int k = 0;k<m;k++){
                        if(train[j][k] == 1){
                            w[j][k] /= 2;
                            if(w[j][k] < 1){
                                w[j][k] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int q;
    scanf("%d",&q);
    int newpic[20][20] = {};
    while(q--){
        int newh = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                scanf("%d",&newpic[i][j]);
                newh += (newpic[i][j]*w[i][j]);
            }
        }
        printf("%d\n",newh>=t);
    }
    
}