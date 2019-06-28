#include <stdio.h>
int main(){
    int n,m,A,B,C,D,E,F,G,H;
    int a=0;
    int b=0;
    scanf("%d%d",&n,&m);
    A=n/1000;B=((n%1000)-(n%100))/100;C=((n%100)-(n%10))/10;D=n%10;
    E=m/1000;F=((m%1000)-(m%100))/100;G=((m%100)-(m%10))/10;H=m%10;
    if(A==E) a++; if(B==F) a++; if(C==G) a++; if(D==H) a++;
    if(A==F) b++; if(A==G) b++; if(A==H) b++; 
    if(B==E) b++; if(B==G) b++; if(B==H) b++;
    if(C==E) b++; if(C==F) b++; if(C==H) b++;
    if(D==E) b++; if(D==F) b++; if(D==G) b++;
    printf("%dA%dB",a,b);
}
