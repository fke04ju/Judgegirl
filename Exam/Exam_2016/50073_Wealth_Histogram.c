#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

typedef struct a{
    char name[20];
    ll money;
}Person;

int cmp(const void *data1,const void *data2){
    Person *ptr1 = (Person *)data1;
    Person *ptr2 = (Person *)data2;
    if(ptr1->money > ptr2->money){
        return 1;
    }else if(ptr1->money < ptr2->money){
        return -1;
    }else{
        if(strcmp(ptr1->name,ptr2->name) > 0){
            return 1;
        }else if(strcmp(ptr1->name,ptr2->name) < 0){
            return -1;
        }else{
            return 0;
        }
    }
}

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen(argv[1],"rb");
    Person table[1025];
    int len = 0;
    while(fread(table[len].name,12,sizeof(char),fp) == 1){
        int a;
        fread(&a,1,sizeof(int),fp);
        table[len].money = a;
        len++;
    }
    qsort(table,len,sizeof(Person),cmp);
    int cnt = 1;
    int tmp = table[0].money/1000;

    for(int i = 1;i<len;i++){
        if(table[i].money/1000 == tmp){
            cnt++;
        }else{
            
            printf("%d\n",cnt);
            cnt = 1;
            tmp = table[i].money/1000;
        }
    }
    printf("%d\n",cnt);
    printf("%s\n",table[0].name);
    for(int i = 0;i<len;i++){
        if(table[len-1].money == table[i].money){
            printf("%s\n",table[i].name);
            break;
        }
    }
    if(len % 2 == 1){
        printf("%d\n",table[len/2].money);
    }else{
        ll aaa = table[len/2].money+table[(len/2)-1].money;
        aaa/=2;
        printf("%lld\n",aaa);
    }
    /*
    for(int i = 0;i<len;i++){
        printf("%s %ld\n",table[i].name,table[i].money);
    }
    */
    fclose(fp);
}