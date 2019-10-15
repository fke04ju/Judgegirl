#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mem_node{
    char member[40];
    struct mem_node *left;
    struct mem_node *right;
}member_node;

typedef struct c_node{
    char clubname[40];
    member_node *mem;
    struct c_node *left;
    struct c_node *right;
}club_node;

member_node *create_mem(member_node *root,char student[]){
    member_node *new;
    if(root == NULL){
        new = (member_node *)malloc(sizeof(member_node));
        strcpy(new->member,student);
        new->left = new->right = NULL;
        return new;
    }
    if(strcmp(root->member,student) > 0){
        root->left = create_mem(root->left,student);
    }else if(strcmp(root->member,student) < 0){
        root->right = create_mem(root->right,student);
    }
    return root;
}

club_node *create(club_node *root,char student[],char club[]){
    club_node *new;
    if(root == NULL){
        new = (club_node *)malloc(sizeof(club_node));
        strcpy(new->clubname,club);
        new->left = new->right = NULL;
        new->mem = NULL;
        new->mem = create_mem(new->mem,student);
        return new;
    }
    if(strcmp(root->clubname,club) > 0){
        root->left = create(root->left,student,club);
    }else if(strcmp(root->clubname,club) < 0){
        root->right = create(root->right,student,club);
    }else{
        root->mem = create_mem(root->mem,student);
    }
    return root;
}

int find_leader(club_node *root,char club[]){
    if(root == NULL){
        return 0;
    }
    if(strcmp(root->clubname,club) == 0){
        printf("%s\n",root->mem->member);
        return 1;
    }
    if(strcmp(root->clubname,club) > 0){
        return find_leader(root->left,club);
    }else{
        return find_leader(root->right,club);
    }
}

int find_mem_in_club(member_node *root,char student[]){
    if(root == NULL){
        return 0;
    }
    if(strcmp(root->member,student) > 0){
        return find_mem_in_club(root->left,student);
    }else if(strcmp(root->member,student) < 0){
        return find_mem_in_club(root->right,student);
    }else{
        return 1;
    }
}

int find_mem(club_node *root,char student[],char club[]){
    if(root == NULL){
        return -1;
    }
    if(strcmp(root->clubname,club) == 0){
        return find_mem_in_club(root->mem,student);
    }
    if(strcmp(root->clubname,club) > 0){
        return find_mem(root->left,student,club);
    }else{
        return find_mem(root->right,student,club);
    }
}

int main(){
    club_node *root = NULL;
    int k,q;
    scanf("%d",&k);
    int ins_cj;
    char name1[40];
    char name2[40];
    for(int i = 0;i<k;i++){
        scanf("%d%s%s",&ins_cj,name1,name2);
        root = create(root,name1,name2);
    }
    int query_num;
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        scanf("%d",&query_num);
        if(query_num == 0){
            scanf("%s",name1);
            int status = find_leader(root,name1);
            if(status == 0){
                printf("None\n");
            }
        }else{
            scanf("%s%s",name1,name2);
            printf("%d\n",find_mem(root,name1,name2));
        }
    }
}