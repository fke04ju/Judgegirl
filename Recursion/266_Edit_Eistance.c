#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *string1,char *string2){
    if(string1[0] == '\0'){
        return strlen(string2);
    }
    if(string2[0] == '\0'){
        return strlen(string1);
    }
    if(string1[0] == string2[0]){
        return compare(string1+1,string2+1);
    }else{
        int d1 = compare(string1+1,string2);
        int d2 = compare(string1,string2+1);
        if(d1 > d2){
            return 1+d2;
        }else{
            return 1+d1;
        }
    }
}

int main(){
    char table[105][15];
    int eistance = 2147483647;
    int id1 = 0;
    int id2 = 0;
    int len = 0;
    while(scanf("%s",table[len])!=EOF){
        len++;
    }
    for(int i = 0;i<len-1;i++){
        for(int j = i+1;j<len;j++){
            int dist;
            if(!strcmp(table[i],table[j])){
                dist = 0;
            }else{
                dist = compare(table[i],table[j]);
            }
            if(dist < eistance){
                eistance = dist;
                id1 = i;
                id2 = j;
            }
//            printf("%d %d %d\n",dist,i+1,j+1);
        }
    }
    printf("%d %d %d",eistance,id1+1,id2+1);
}