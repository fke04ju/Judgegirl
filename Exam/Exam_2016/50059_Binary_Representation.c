#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char alphabet[32];
    scanf("%s",alphabet);
    int num;
    scanf("%d",&num);
    int a;
    int count = 0;
    int value = 0;
    while(scanf("%d",&a)!=EOF){
        for(int i = 31;i>=0;i--){
            value <<= 1;
            value |= ((a >> i)&1);
            count ++;
            if(count == 5){
                printf("%c",alphabet[value]);
                value = 0;
                count = 0;
            }
        }
    }
    puts("");
}