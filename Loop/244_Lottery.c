#include <stdio.h>
int main(){
    int first_1,first_2,first_3,super_1,super_2,super_3,lottery;
    int sum=0;
    scanf("%d%d%d%d%d%d",&super_1,&super_2,&super_3,&first_1,&first_2,&first_3);
    while(scanf("%d",&lottery)!=EOF){
        if(lottery==super_1) sum+=2000000;
        else if(lottery==super_2) sum+=2000000;
        else if(lottery==super_3) sum+=2000000;
        else if(lottery==first_1) sum+=200000;
        else if(lottery==first_2) sum+=200000;
        else if(lottery==first_3) sum+=200000;
        else if((lottery%10000000)==(first_1%10000000)) sum+=40000;
        else if((lottery%10000000)==(first_2%10000000)) sum+=40000;
        else if((lottery%10000000)==(first_3%10000000)) sum+=40000;
        else if((lottery%1000000)==(first_1%1000000)) sum+=10000;
        else if((lottery%1000000)==(first_2%1000000)) sum+=10000;
        else if((lottery%1000000)==(first_3%1000000)) sum+=10000;
        else if((lottery%100000)==(first_1%100000)) sum+=4000;
        else if((lottery%100000)==(first_2%100000)) sum+=4000;
        else if((lottery%100000)==(first_3%100000)) sum+=4000;
        else if((lottery%10000)==(first_1%10000)) sum+=1000;
        else if((lottery%10000)==(first_2%10000)) sum+=1000;
        else if((lottery%10000)==(first_3%10000)) sum+=1000;
        else if((lottery%1000)==(first_1%1000)) sum+=200;
        else if((lottery%1000)==(first_2%1000)) sum+=200;
        else if((lottery%1000)==(first_3%1000)) sum+=200;
        else sum+=0;
    }
    printf("%d",sum);
}
