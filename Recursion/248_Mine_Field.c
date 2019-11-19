#include <stdio.h>
#include <stdlib.h>
int field[9][9] = {};
int answer[9][9] = {};
int dx[9] = {-1,-1,0,1,1,1,0,-1,0};
int dy[9] = {0,1,1,1,0,-1,-1,-1,0};

int out_of_bound(int x,int y,int i){
    if(x+dx[i] >= 0 && x+dx[i] < 9 && y+dy[i] >= 0 && y+dy[i] < 9){
        return 1;
    }else{
        return 0;
    }
}

int check_if_around_elem_are_greater_than_0(int x,int y){
    for(int i = 0;i<9;i++){
        if(out_of_bound(x,y,i)){
            if(field[x+dx[i]][y+dy[i]] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void sub_around(int x,int y){
    for(int i = 0;i<9;i++){
        if(out_of_bound(x,y,i)){
            field[x+dx[i]][y+dy[i]] --;
        }
    }
    return;
}

void add_around(int x,int y){
    for(int i = 0;i<9;i++){
        if(out_of_bound(x,y,i)){
            field[x+dx[i]][y+dy[i]] ++;
        }
    }
    return;
}

void print(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            printf("%d%c",answer[i][j],(j<8)?' ':'\n');
        }
    }
    return;
}

void find(int x,int y){
    if(x == 8 && y == 8){
        if(field[8][7] == 0 && field[8][8] == 0 && field[7][8] == 0 && field[7][7] == 0){
            print();
            exit(0);
        }
        if(check_if_around_elem_are_greater_than_0(x,y) == 1){
            sub_around(x,y);
            answer[x][y] = 1;
            if(field[8][7] == 0 && field[8][8] == 0 && field[7][8] == 0 && field[7][7] == 0){
                print();
                exit(0);
            }
            add_around(x,y);
            answer[x][y] = 0;
            return;
        }
    }else if(x == 8){
        if(y == 0 || (field[8][y-1] == 0 && field[7][y-1] == 0)){
            find(x,y+1);
        }
        if(check_if_around_elem_are_greater_than_0(x,y) == 1){
            sub_around(x,y);
            answer[x][y] = 1;
            if(y == 0 || (field[8][y-1] == 0 && field[7][y-1] == 0)){
                find(x,y+1);
            }
            add_around(x,y);
            answer[x][y] = 0;
            return;
        }
    }else if(y == 8){
        if(x == 0 || (field[x-1][8] == 0 && field[x-1][7] == 0)){
            find(x+1,0);
        }
        if(check_if_around_elem_are_greater_than_0(x,y) == 1){
            sub_around(x,y);
            answer[x][y] = 1;
            if(x == 0 || (field[x-1][8] == 0 && field[x-1][7] == 0)){
                find(x+1,0);
            }
            add_around(x,y);
            answer[x][y] = 0;
            return;
        }
    }else{
        if((x == 0 || y == 0) || (field[x-1][y-1] == 0)){
            find(x,y+1);
        }
        if(check_if_around_elem_are_greater_than_0(x,y) == 1){
            sub_around(x,y);
            answer[x][y] = 1;
            if((x == 0 || y == 0) || (field[x-1][y-1] == 0)){
                find(x,y+1);
            }
            add_around(x,y);
            answer[x][y] = 0;
            return;
        }
    }
}

int main(){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            scanf("%d",&field[i][j]);
        }
    }
    find(0,0);
    printf("no solution\n");
    return 0;
}