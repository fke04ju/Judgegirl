#include <stdio.h>
 
int main() {
    int year,month,week,days;
    int i,j;
    int total=1;
    scanf("%d%d%d",&year,&month,&week);
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: days=31;break;
        case 4: case 6: case 9: case 11: days=30;break;
        case 2:{
            if(year%400==0 || (year%4==0 && year%100!=0)){
                days=29;break;
            }else{
                days=28;break;
            }
        }
    }
    if(month<1 || month>12){
        printf("invalid\n");
    }else if(week<0 || week>6){
        printf("invalid\n");
    }else{
        printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
        for(i=0;i<week;i++){
            printf("   ");
        }
        for(i=0;i<7-week;i++){
            printf("%3d",total);
            total++;
        }
        printf("\n");
        for(i=0;i<=(days+week-8)/7;i++){
            for(j=0;j<7;j++){
                if(total>days){
                    break;
                }else{
                    printf("%3d",total);
                    total++;
                }
            }
            printf("\n");
        }
        printf("=====================\n");
    }
}
