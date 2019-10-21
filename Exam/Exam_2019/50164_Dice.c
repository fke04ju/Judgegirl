#include <stdio.h>
#include <stdlib.h>
 
int dice[1050][1050] = {};
int ans = 0;
 
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            scanf("%d",&dice[i][j]);
        }
    }
    int num[7] = {};
    for(int i = 1;i<r-1;i++){
        for(int j = 0;j<c-3;j++){
            if(num[dice[i][j]] == 0 && num[dice[i][j+2]] == 0 && dice[i][j]+dice[i][j+2] == 7){
                num[dice[i][j]] = 1;
                num[dice[i][j+2]] = 1;
                if(num[dice[i][j+1]] == 0 && num[dice[i][j+3]] == 0 && dice[i][j+1]+dice[i][j+3] == 7){
                    num[dice[i][j+1]] = 1;
                    num[dice[i][j+3]] = 1;
                    for(int k = 0;k<4;k++){
                        if(num[dice[i-1][j+k]] == 0){
                            num[dice[i-1][j+k]] = 1;
                            for(int w = 0;w<4;w++){
                                if(num[dice[i+1][j+w]] == 0 && dice[i+1][j+w]+dice[i-1][j+k] == 7){
                                    ans++;
                                }
                            }
                            num[dice[i-1][j+k]] = 0;
                        }
                    }
                    num[dice[i][j+1]] = 0;
                    num[dice[i][j+3]] = 0;
                }
                num[dice[i][j]] = 0;
                num[dice[i][j+2]] = 0;
            }
        }
    }
    printf("%d\n",ans);
}