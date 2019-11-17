#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned char table[100] = {};
    int N,M,P;
    unsigned long long int in;
    int count = 0;
    int flag = 0;
    scanf("%d%d%d",&N,&M,&P);
    while(M--){
        scanf("%llu",&in);
        for(int i = 7;i>=0 && flag == 0;i--){
            unsigned char tmp = 0;
            tmp |= (in >> i*8);
            table[count] |= tmp;
            count ++;
        }
    }
    unsigned char c;
    while(scanf("%hhu",&c)!=EOF){
        int index = 0;
        int find_complete = 0;
        int find_one = 0;
        for(int i = 0;i<N;i++){
            unsigned char tmp = 0;
            tmp |= (c ^ table[i]);
            if(tmp == 0){
                find_complete = 1;
            }else if(tmp == 1 || tmp == 2 || tmp == 4 || tmp == 8 || tmp == 16 || tmp == 32 || tmp == 64 || tmp == 128){
                index = i;
                find_one = 1;
            }
        }
        if(find_complete == 1){
            printf("%hhu\n",c);
        }else if(find_one == 1){
            unsigned char tmp2 = 0;
            tmp2 |= (c ^ table[index]);
            c ^= tmp2;
            printf("%hhu\n",c);
        }
    }
}