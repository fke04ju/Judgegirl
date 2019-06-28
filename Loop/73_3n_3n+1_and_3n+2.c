#include <stdio.h>
 
int main(){
    int n,i,a;
    int x=0,y=0,z=0;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a%3 == 0) x++;
        else if(a%3 == 1) y++;
        else z++;
    }
    printf("%d %d %d",x,y,z);
}
