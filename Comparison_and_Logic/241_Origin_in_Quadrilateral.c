#include <stdio.h>
int main(){
	int a,b,c,d,e,f,g,h;
	int k;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	k=((a*d-b*c>0) && (c*f-d*e>0)) && ((e*h-f*g>0) && (g*b-h*a>0));
	printf("%d",k);
}
