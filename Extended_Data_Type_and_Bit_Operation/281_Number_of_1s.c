#include <stdio.h>
int main(){
    int n;
    int one=1;
    while(scanf("%d",&n)!=EOF){
        int count=0;
        while(n>0){
            if(n & one){
                count++;
            }
            n>>=1;
        }
        printf("%d\n",count);
    }
}