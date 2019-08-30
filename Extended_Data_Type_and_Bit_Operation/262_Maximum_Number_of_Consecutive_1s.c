#include <stdio.h>
int main(){
    int n;
    int one=1;    
    while(scanf("%d",&n)!=EOF){
        int count=0;
        int max=0;
        while(n>0){
            if(n & one){
                count++;
                if(count>max){
                    max=count;
                }
            }else{
                count=0;
            }
            n>>=1;
        }
        printf("%d\n",max);
    }
}