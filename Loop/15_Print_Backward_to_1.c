#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=n;i>0;i--){
        printf("%d\n",n);
        n-=1;
    }
}
