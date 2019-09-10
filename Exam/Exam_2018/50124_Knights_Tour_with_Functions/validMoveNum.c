#include "validMoveNum.h"
int validMoveNum(int r, int c, int n, int visited[100][100]){
    if(r >= n || c >= n || r < 0 || c < 0 || visited[r][c] == 1){
        return -1;
    }
    int cnt = 0;
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    for(int i = 0;i<8;i++){
        int new_r = r+move[i][0];
        int new_c = c+move[i][1];
        if(new_r < n && new_r >= 0 && new_c < n && new_c >= 0 && visited[new_r][new_c] == 0){
            cnt++;
        }
    }
    return cnt;
}