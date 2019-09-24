#include <stdio.h>
 
int main(){
    int k;
    scanf("%d",&k);
    int sum = 0;
    int cp;
    scanf("%d",&cp);
    int at = cp%3;
    int wind = 0;
    int fire = 0;
    int water = 0;
    if(cp%3 == 0){
        wind++;
    }else if(cp%3 == 1){
        fire ++;
    }else{
        water++;
    }
    int deputy = 0;
    int max = cp;
    while(scanf("%d",&cp)!=EOF){
        if(wind >= k && fire>=k && water>=k){
            sum+=deputy;
            deputy = 0;
            max = cp;
            wind = 0;
            water = 0;
            fire = 0;
            if(cp%3 == 0){
                wind++;
            }else if(cp%3 == 1){
                fire ++;
            }else{
                water++;
            }
        }else{
            if(cp%3 == 0){
                wind++;
            }else if(cp%3 == 1){
                fire ++;
            }else{
                water++;
            }
            if(cp > max){
                deputy = max;
                max = cp;
            }else if(cp >= deputy){
                deputy = cp;
            }
        }
    }
    if(wind+fire+water == 1){
        sum += max;
    }else{
        sum += deputy;
    }
    printf("%d\n",sum);
    return 0;
}