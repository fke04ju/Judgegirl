#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name_to_book[100][100][50] = {};
int book_num[100] = {};
char author[100][50] = {};
int total_books[100] = {};

int main(){
    char name[100],book[100];
    int n;
    int count = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s%s",name,book);
        int flag = 0;
        for(int j = 0;j<count && flag == 0;j++){
            if(!strcmp(author[j],name)){
                strcpy(name_to_book[j][book_num[j]],book);
                book_num[j]++;
                flag = 1;
            }
        }
        if(flag == 0){
            strcpy(author[count],name);
            strcpy(name_to_book[count][book_num[count]],book);
            book_num[count]++;
            count ++;
        }
    }
    char book_name[100];
    int num;
    while(scanf("%s%d",book_name,&num)!=EOF){
        for(int i = 0;i<count;i++){
            for(int j = 0;j<book_num[i];j++){
                if(!strcmp(name_to_book[i][j],book_name)){
                    total_books[i] += num;
                }
            }
        }
    }
    int max = 0;
    int idx = -1;
    for(int i = 0;i<count;i++){
        if(max < total_books[i]){
            idx = i;
            max = total_books[i];
        }
    }
    for(int i = 0;i<count;i++){
        if(max == total_books[i]){
            if(strcmp(author[idx],author[i]) > 0){
                idx = i;
            }
        }
    }
    printf("%s %d\n",author[idx],max);
}