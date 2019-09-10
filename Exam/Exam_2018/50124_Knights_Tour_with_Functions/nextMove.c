#include "nextMove.h"
#include "validMoveNum.h"
int nextMove(int r, int c, int n, int visited[100][100]){
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int p[8] = {};
    int min_index = -1;
    int min_p = 8;
    for(int i = 0;i<8;i++){
        p[i] = validMoveNum(r+move[i][0],c+move[i][1],n,visited);
    }
    for(int i = 0;i<8;i++){
        if(min_p > p[i] && p[i] > -1){
            min_p = p[i];
            min_index = i;
        }
    }
    return min_index;
}