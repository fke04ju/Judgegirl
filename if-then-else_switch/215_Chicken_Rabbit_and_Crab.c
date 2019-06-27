#include <stdio.h>
main(){
    int s,f,t,a,b,c;
    scanf("%d%d%d",&s,&f,&t);
    c=s-t;
    b=((6*t)+f-(8*s))*0.5;
    a=t-b;
    if(a,b,c>=0 && (a+b+c == s && (2*a+4*b+8*c == f && a+b == t))){
		printf("%d\n%d\n%d",a,b,c);
	}else{
		printf("%d",0);
	}
}
