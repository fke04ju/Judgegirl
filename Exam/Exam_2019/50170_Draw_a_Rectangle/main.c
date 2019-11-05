#include <stdio.h>
#include <string.h>
#include "fill_rectangle.h"
int main(){
        int row, col, type, row1, col1, row2, col2, fill;
        scanf("%d%d%d", &row, &col, &type);
        int arr[row][col];
        memset(&(arr[0][0]), 0, sizeof(int) * row * col);
        while(scanf("%d%d%d%d%d", &row1, &col1, &row2, &col2, &fill) != EOF){
                //printf("%d %d %d %d %d\n", row1, col1, row2, col2, fill);
                if(type == 0)
                        fill_rectangle_neg(&(arr[row1][col1]), &(arr[row2][col2]), row, col, fill);
                else
                        fill_rectangle_pos(&(arr[row1][col1]), &(arr[row2][col2]), row, col, fill);
        }
        for(int i = 0; i < row; i++)
                for(int j = 0; j < col; j++)
                        printf("%d%c", arr[i][j], j == col - 1 ? '\n' : ' ');
        return 0;
}