#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    int h_index;
    char name[16];
}Person;

int cmp(const void *data1,const void *data2){
    Person *a = (Person *)data1;
    Person *b = (Person *)data2;
    if(strcmp(a->name,b->name) > 0){    // a's name larger than b's
        return 1;
    }else if(strcmp(a->name,b->name) < 0){
        return -1;
    }else{
        if(a->h_index < b->h_index){
            return 1;
        }else if(a->h_index > b->h_index){
            return -1;
        }else{
            return 0;
        }
    }
}

int main(){
    Person list[20000];
    int len = 0;
    while(scanf("%s%d",list[len].name,&list[len].h_index) != EOF){
        len++;
    }
    qsort(list,len,sizeof(Person),cmp);
    int now_index = 0;
    int check = 0;
    char tmp[16];
    strcpy(tmp,list[0].name);
    for(int i = 0;i<len;i++){
        if(!strcmp(tmp,list[i].name)){
            now_index++;
        }else{
            if(check == 0){
                printf("%s %d\n",list[i-1].name,now_index);
            }
            strcpy(tmp,list[i].name);
            now_index = 1;
            check = 0;
        }
        if(now_index > list[i].h_index && check == 0){
            printf("%s %d\n",list[i].name,now_index-1);
            check = 1;
        }
    }
    if(check == 0){
        printf("%s %d\n",list[len-1].name,now_index);
    }
}