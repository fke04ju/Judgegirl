#include <stdio.h>
int space[32768]={ 0 };
int main(){
    int row,column;
    char one[2];
    char zero[2];
    unsigned int number;
    scanf("%d%d%s%s",&column,&row,one,zero);
    int space[row*column+1];
    for(int i=0;i<row*column;i++){
        space[i]=0;
    }    
//    int map[row][column];
/*    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            map[i][j]=0;
        }
    }*/
    int count=0;int next=0;
    unsigned int compare=2147483648;
    while(scanf("%u",&number)!=EOF){
        int cnt=32;
        while(cnt--){
            if(compare & number){
                space[count]=1;
            }else{
                space[count]=0;
            }
            number <<= 1;
            if(count>row*column){
                break;
            }
            count ++;
        }
/*        for(int i=next;i<=count;i++){
            printf("%d",space[i]);
            if((i+1)%column==0){
                printf("\n");
            }
        }*/
        next=count;
    }
//    printf("\n");
    int anothercount=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(space[anothercount]==1){
                printf("%s",one);
                anothercount++;
            }else{
                printf("%s",zero);
                anothercount++;
            }
        }
        printf("\n");
    }
}