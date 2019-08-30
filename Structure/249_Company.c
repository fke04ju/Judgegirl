#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct employee{
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
}employee;
 
employee company[32];
 
int sub(int n,char name1_f[],char name1_l[],char name2_f[],char name2_l[]){
    int self_index;
    int check = 0;
    for(int i = 0;i<n && check == 0;i++){
        if(!strcmp(name1_f,company[i].first_name) && !strcmp(name1_l,company[i].last_name)){
            self_index = i;
            check = 1;
        }
    }
    int bosses[32] = {};
    int len = 0;
    while(company[self_index].id != company[self_index].boss_id){
        bosses[len] = company[self_index].boss_id;
        len++;
        int bossid = company[self_index].boss_id;
        int check1 = 0;
        for(int i = 0;i<n && check1 == 0;i++){
            if(company[i].id == bossid){
                self_index = i;
                check1 = 1;
            }
        }
    }
    int ask_id;
    check = 0;
    for(int i = 0;i<n && check == 0;i++){
        if(!strcmp(name2_f,company[i].first_name) && !strcmp(name2_l,company[i].last_name)){
            ask_id = company[i].id;
            check = 1;
        }
    }
    for(int i = 0;i<len;i++){
        if(bosses[i] == ask_id){
            return 1;
        }
    }
    return 0;
}
 
int col(int n,char name1_f[],char name1_l[],char name2_f[],char name2_l[]){
    int bosses_1[32] = {};
    int bosses_2[32] = {};
    int len_1 = 0;
    int len_2 = 0;
    int index_1,index_2;
    for(int i = 0;i<n;i++){
        if(!strcmp(company[i].first_name,name1_f) && !strcmp(company[i].last_name,name1_l)){
            index_1 = i;
        }
        if(!strcmp(company[i].first_name,name2_f) && !strcmp(company[i].last_name,name2_l)){
            index_2 = i;
        }
    }
    while(company[index_1].id != company[index_1].boss_id){
        bosses_1[len_1] = company[index_1].boss_id;
        len_1 ++;
        int check = 0;
        for(int i = 0;i<n && check == 0;i++){
            if(company[i].id == company[index_1].boss_id){
                index_1 = i;
                check = 1;
            }
        }
    }
    while(company[index_2].id != company[index_2].boss_id){
        bosses_2[len_2] = company[index_2].boss_id;
        len_2 ++;
        int check = 0;
        for(int i = 0;i<n && check == 0;i++){
            if(company[i].id == company[index_2].boss_id){
                index_2 = i;
                check = 1;
            }
        }
    }
    if(bosses_1[len_1-1] == bosses_2[len_2-1]){
        return 1;
    }else{
        return 0;
    }
}
 
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%s%s%d",&(company[i].id),company[i].first_name,company[i].last_name,&company[i].boss_id);
    }
    int q;
    char name1_f[32];
    char name1_l[32];
    char name2_f[32];
    char name2_l[32];
    scanf("%d",&q);
    while(q--){
        scanf("%s%s%s%s",name1_f,name1_l,name2_f,name2_l);
        if(sub(n,name1_f,name1_l,name2_f,name2_l) == 1){
            printf("subordinate\n");
        }else if(sub(n,name2_f,name2_l,name1_f,name1_l) == 1){
            printf("supervisor\n");
        }else if(col(n,name1_f,name1_l,name2_f,name2_l) == 1){
            printf("colleague\n");
        }else{
            printf("unrelated\n");
        }
    }
}