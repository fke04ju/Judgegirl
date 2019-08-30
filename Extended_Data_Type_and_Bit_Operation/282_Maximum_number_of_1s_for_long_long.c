#include <stdio.h>
int main(){
    long long n;
    long long one=1;    
    while(scanf("%lld",&n)!=EOF){
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