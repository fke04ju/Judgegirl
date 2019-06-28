#include <stdio.h>
 
int main(){
    int a,i,j;
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        int n=1;
        for(j=0;j<i;j++){
            printf("%d",n);
            n++;
        }
    }
}
