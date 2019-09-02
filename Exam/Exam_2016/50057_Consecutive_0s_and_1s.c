#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int len = 0;
    int arr[33];
    int now = 0;
    int count = 1;
    while(scanf("%d",&a[len]) != EOF){
        len++;
        for(int i = 32;i>0;i--){
            arr[i] = a[len-1]%2;
            a[len-1]/=2;
        }
        for(int i = 1;i<=32;i++){
            if(arr[i] == now){
                printf("%d",arr[i]);
            }else{
                now = arr[i];
                printf("\n");
                for(int j = 0;j<(count-1)%40;j++){
                    printf(" ");
                }
                printf("%d",arr[i]);
            }
            count++;
        }
    }
    puts("");
    /*
    for(int i =1;i<65;i++){
        printf("%d",arr[i]);
    }
    */
}