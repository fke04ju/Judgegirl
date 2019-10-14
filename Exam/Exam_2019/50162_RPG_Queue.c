#include <stdio.h>
 
int main(){
    int queue_dps[5000];
    int queue_healer[5000];
    int queue_tank[5000];
    int num;
    int front = 0;
    int rear = -1;
    int ptr_healer_front = 0;
    int ptr_healer_rear = -1;
    int ptr_tank_front = 0;
    int ptr_tank_rear = -1;
    while(scanf("%d",&num)!=EOF){
        if(num % 3 == 0){
            rear++;
            queue_dps[rear%5000] = num;
        }else if(num % 3 == 1){
            ptr_healer_rear ++;
            queue_healer[ptr_healer_rear%5000] = num;
        }else{
            ptr_tank_rear ++;
            queue_tank[ptr_tank_rear%5000] = num;
        }
        if(rear-front >= 2 && ptr_healer_rear >= ptr_healer_front && ptr_tank_rear >= ptr_tank_front){
            printf("%d %d %d ",queue_dps[front%5000],queue_dps[(front+1)%5000],queue_dps[(front+2)%5000]);
            front+=3;
            printf("%d %d\n",queue_healer[ptr_healer_front%5000],queue_tank[ptr_tank_front%5000]);
            ptr_tank_front++;
            ptr_healer_front++;
        }
    }
}