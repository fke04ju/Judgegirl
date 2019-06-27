#include <stdio.h>

int main(){
	int x;
	int a;
	scanf("%d",&x);
	a = (x%15 != 0) || (x%105 == 0);
	printf("%d",a);
}
