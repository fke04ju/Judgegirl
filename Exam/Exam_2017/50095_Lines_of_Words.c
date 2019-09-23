#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **first_table[1024];
char *second_table[16384];
char word[10000000];
int first_table_num[1024];

int main(){
    int n;
    scanf("%d",&n);
    int word_num = 0;
    int id = 0;
    for(int i = 0;i<n;i++){
        char _;
        first_table[i] = &second_table[word_num];
        while(scanf("%s%c",&word[id],&_) == 2){
            second_table[word_num] = &word[id];
            word_num++;
            first_table_num[i]++;
            id += strlen(&word[id])+1;
            if(_ == '\n'){
                break;
            }
        }
    }
    int m;
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        char *tmp = first_table[x1][x2];
        first_table[x1][x2] = first_table[y1][y2];
        first_table[y1][y2] = tmp;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<first_table_num[i];j++){
            printf("%s%c",first_table[i][j],(j<first_table_num[i]-1)?' ':'\n');
        }
    }
    return 0;
}