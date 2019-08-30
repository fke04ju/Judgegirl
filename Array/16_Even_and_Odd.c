#include <stdio.h>
 
int main() {
    int n,i;
    scanf("%d",&n);
    int x[n];
    int a[n];
    int b[n];
    int count_a=0;
    int count_b=0;
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
        if(x[i]%2==0){  //填入偶數
            a[count_a]=x[i];
            count_a+=1;
        }else{  //填入奇數
            b[count_b]=x[i];
            count_b+=1;
        }
    }
    printf("%d",b[0]);
    for(i=1;i<count_b;i++){  //印出奇數
        printf(" %d",b[i]);
    }
    printf("\n");
    printf("%d",a[0]);
    for(i=1;i<count_a;i++){  //印出偶數
        printf(" %d",a[i]);
    }
}