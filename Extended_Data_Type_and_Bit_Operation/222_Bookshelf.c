#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main(){
    int n;
    int shelf[8] = { 0 };
    while(ReadInt(&n)){
        int flag = -1;
        for(int i = 0;i<8;i++){
            if(shelf[i] == n){
                flag = i;
            }
        }
        if(flag == -1){
            for(int i = 0;i<7;i++){
                shelf[i] = shelf[i+1];
            }
            shelf[7] = n;
        }else{
            for(int i = flag;i<7;i++){
                shelf[i] = shelf[i+1];
            }
            shelf[7] = n;
        }
    }
    for(int i = 0;i<8;i++){
        printf("%d%c",shelf[i],(i!=7)? ' ': '\n');
    }
    return 0;
}