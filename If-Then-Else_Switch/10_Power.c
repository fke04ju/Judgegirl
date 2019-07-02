#include <stdio.h>
 
int main() {
    int i,n,j;
    int sum=1;
    scanf("%d\n%d",&i,&n);
    for(j=0;j<n;j++){
        sum = sum*i;
    }
	printf("%d",sum);
}
