#include <stdio.h>
int main(){
	int a,b,c;
	int k;
	scanf("%d\n%d\n%d\n",&a,&b,&c);
	k = (a+b > c) && ((a+c > b) && (b+c > a));
	printf("%d",k);
}
