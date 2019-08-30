#include <stdio.h>
 
int gcd(int m, int n) {
    while(n != 0) { 
        int r = m % n; 
        m = n; 
        n = r; 
    } 
    return m;
}
 
int lcm(int m, int n) {
    return m * n / gcd(m, n);
}
 
int main(void) {
    int n;
    scanf("%d",&n);
    int m;
    int i;
    while(scanf("%d",&m)!=EOF){
        n=lcm(n,m);
    }
    printf("%d",n);
}