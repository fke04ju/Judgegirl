#include "fraction.h"

long long gcd(long long a,long long b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

Frac normal(long long a, long long b){
    int gcd_ab = gcd(a,b);
    Frac c;
    c.a = a/gcd_ab;
    c.b = b/gcd_ab;
    return c;
}
Frac add(Frac x, Frac y){
    int upper = x.a*y.b+x.b*y.a;
    int down = x.b*y.b;
    Frac z;
    int gcd_xy = gcd(upper,down);
    z.a = upper/gcd_xy;
    z.b = down/gcd_xy;
    return z;
}
Frac subtract(Frac x, Frac y){
    int upper = x.a*y.b-x.b*y.a;
    int down = x.b*y.b;
    Frac z;
    int gcd_xy = gcd(upper,down);
    z.a = upper/gcd_xy;
    z.b = down/gcd_xy;
    return z;
}
Frac multipy(Frac x, Frac y){
    int upper = x.a*y.a;
    int down = x.b*y.b;
    Frac z;
    int gcd_xy = gcd(upper,down);
    z.a = upper/gcd_xy;
    z.b = down/gcd_xy;
    return z;
}
Frac divide(Frac x, Frac y){
    int upper = x.a*y.b;
    int down = x.b*y.a;
    Frac z;
    int gcd_xy = gcd(upper,down);
    z.a = upper/gcd_xy;
    z.b = down/gcd_xy;
    return z;
}