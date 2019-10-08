#include <stdio.h>

int main(){
    int num;
    int comp[101] = {};
    for(int i = 0;i<101;i++){
        comp[i] = -1;
    }
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&num);
        if(comp[num] == -1){
            comp[num] = i;
            printf("%d\n",i);
        }else{
            printf("%d %d %d\n",i,comp[num],num);
            comp[num] = -1;
        }
    }
}