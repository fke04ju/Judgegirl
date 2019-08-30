#include <stdio.h>
#define pi 3.1415926
double ca(double a,double b, double c){
    double r;
    r=c*c*pi*3/4+(c-a)*(c-a)*pi/4;
    return r;
}
double cb(double a, double b, double c){
    double r;
    r=c*c*pi*3/4+(c-b)*(c-b)*pi/4;
    return r;
}
double cc(double a, double b, double c){
    double r;
    r=c*c*pi*3/4;
    return r;
}
double cab(double a, double b, double c){
    double r;
    r=c*c*pi*3/4+(c-a)*(c-a)*pi/4+(c-b)*(c-b)*pi/4;
    return r;
}
int main(){
    double a,b,c;
    double sum;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a<c && b>c){
        sum=ca(a,b,c);
    }else if(b<c && a>c){
        sum=cb(a,b,c);
    }else if(a<c && b<c){
        sum=cab(a,b,c);
    }else{
        sum=cc(a,b,c);
    }
    printf("%f",sum);
}