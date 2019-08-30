#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    int a[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=2;
        }
    }
    int x,y;
    int black=0;
    int white=0;
    int black_start=1;
    int white_start=1;
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        if(a[x][y]==2 && black_start>=white_start){
            a[x][y]=1;
            white_start++;
        }else if(a[x][y]==2 && white_start>=black_start){
            a[x][y]=0;
            black_start++;
        }else{
            continue;
        }
    if(a[0][0]==a[0][1] && a[0][1]==a[0][2] && a[0][0]==1){
        black=1;break;
    }else if(a[0][0]==a[0][1] && a[0][1]==a[0][2] && a[0][0]==0){
        white=1;break;
    }else if(a[1][0]==a[1][1] && a[1][1]==a[1][2] && a[1][0]==1){
        black=1;break;
    }else if(a[1][0]==a[1][1] && a[1][1]==a[1][2] && a[1][0]==0){
        white=1;break;
    }else if(a[2][0]==a[2][1] && a[2][1]==a[2][2] && a[2][0]==1){
        black=1;break;
    }else if(a[2][0]==a[2][1] && a[2][1]==a[2][2] && a[2][0]==0){
        white=1;break;
    }else if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==1){
        black=1;break;
    }else if(a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==0){
        white=1;break;
    }else if(a[2][0]==a[1][1] && a[1][1]==a[0][2] && a[2][0]==1){
        black=1;break;
    }else if(a[2][0]==a[1][1] && a[1][1]==a[0][2] && a[2][0]==0){
        white=1;break;
    }else if(a[0][0]==a[1][0] && a[1][0]==a[2][0] && a[0][0]==1){
        black=1;break;
    }else if(a[0][0]==a[1][0] && a[1][0]==a[2][0] && a[0][0]==0){
        white=1;break;
    }else if(a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[0][1]==1){
        black=1;break;
    }else if(a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[0][1]==0){
        white=1;break;
    }else if(a[0][2]==a[1][2] && a[1][2]==a[2][2] && a[0][2]==1){
        black=1;break;
    }else if(a[0][2]==a[1][2] && a[1][2]==a[2][2] && a[0][2]==0){
        white=1;break;
    }
    }
    if(black==1){
        printf("Black wins.");
    }else if(white==1){
        printf("White wins.");
    }else if(a[0][0]==2 || a[0][1]==2 || a[0][2]==2 || a[1][0]==2 || a[1][1]==2 || a[1][2]==2 || a[2][0]==2 || a[2][1]==2 || a[2][2]==2){
        printf("There is a draw.");
    }else printf("There is a draw.");
}