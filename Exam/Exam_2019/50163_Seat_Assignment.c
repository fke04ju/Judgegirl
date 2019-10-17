#include <stdio.h>

int train[1001][21][6];

int main(){
    int car_num;
    int query;
    int one_index_row = 1;
    int one_index_column = 1;
    int two_index_row = 1;
    int two_index_column = 1;
    scanf("%d",&car_num);
    int now_car_one = 1;
    int now_car_two = 1;
    int double_seat_not_found = 0;
    while(scanf("%d",&query) != EOF){
        if(query == 1){
            while(train[now_car_one][one_index_row][one_index_column] == 1){
                if(one_index_column == 5){
                    one_index_column = 1;
                    if(one_index_row == 20){
                        one_index_row = 1;
                        now_car_one++;
                    }else{
                        one_index_row++;
                    }
                }else{
                    one_index_column++;
                }
            }
            train[now_car_one][one_index_row][one_index_column] = 1;
            printf("%d %d %d\n",now_car_one,one_index_row,one_index_column);
        }else{
            if(double_seat_not_found == 0){
                while(train[now_car_two][two_index_row][two_index_column] == 1){
                    if(two_index_column == 5){
                        two_index_column = 1;
                        if(two_index_row == 20){
                            two_index_row = 1;
                            now_car_two++;
                        }else{
                            two_index_row++;
                        }
                    }else{
                        two_index_column++;
                    }
                }
                if((two_index_column == 3 || two_index_column == 5)){
                    if(two_index_column == 5){
                        two_index_column = 1;
                        if(two_index_row == 20){
                            two_index_row = 1;
                            now_car_two++;
                        }else{
                            two_index_row ++;
                        }
                    }else{
                        two_index_column ++;
                    }
                }
                if(now_car_two > car_num){
                        two_index_row = 1;
                        two_index_column = 1;
                        now_car_two = 1;
                        double_seat_not_found = 1;
                }else{
                    train[now_car_two][two_index_row][two_index_column] = 1;
                    printf("%d %d %d ",now_car_two,two_index_row,two_index_column);
                    train[now_car_two][two_index_row][two_index_column+1] = 1;
                    printf("%d %d %d\n",now_car_two,two_index_row,two_index_column+1);
                }
            }
            if(double_seat_not_found == 1){
                while(train[now_car_two][two_index_row][two_index_column] == 1){
                    if(two_index_column == 5){
                        two_index_column = 1;
                        if(two_index_row == 20){
                            two_index_row = 1;
                            now_car_two++;
                        }else{
                            two_index_row++;
                        }
                    }else{
                        two_index_column++;
                    }
                }
                train[now_car_two][two_index_row][two_index_column] = 1;
                printf("%d %d %d ",now_car_two,two_index_row,two_index_column);
                while(train[now_car_two][two_index_row][two_index_column] == 1){
                    if(two_index_column == 5){
                        two_index_column = 1;
                        if(two_index_row == 20){
                            two_index_row = 1;
                            now_car_two++;
                        }else{
                            two_index_row++;
                        }
                    }else{
                        two_index_column++;
                    }
                }
                train[now_car_two][two_index_row][two_index_column] = 1;
                printf("%d %d %d\n",now_car_two,two_index_row,two_index_column);
            }
        }
    }
}