#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char a[10],b[10],c[30];
int printed = 0;

int hash(char word[]){
    int ans = 0;
    for(int i = 0;i<strlen(word);i++){
        ans*=10;
        ans+=word[i]-'0';
    }
    return ans;
}

int turn(int word[26][2],int n){
    char tmp_a[10],tmp_b[20],tmp_c[20];
    strcpy(tmp_a,a);
    strcpy(tmp_b,b);
    strcpy(tmp_c,c);
    for(int w = 0;w<n;w++){
        for(int i = 0;i<strlen(tmp_a);i++){
            if(tmp_a[i] == word[w][0]){
                tmp_a[i] = word[w][1]+'0';
            }
        }
        for(int i = 0;i<strlen(tmp_b);i++){
            if(tmp_b[i] == word[w][0]){
                tmp_b[i] = word[w][1]+'0';
            }
        }
        for(int i = 0;i<strlen(tmp_c);i++){
            if(tmp_c[i] == word[w][0]){
                tmp_c[i] = word[w][1]+'0';
            }
        }
    }
    if(hash(tmp_a)*hash(tmp_b) == hash(tmp_c)){
        printf("%s x %s = %s\n",tmp_a,tmp_b,tmp_c);
        return 1;
    }else{
        return 0;
    }
}

void permutation(int word[26][2],int index,int n){
    if(printed == 1){
        return;
    }
    if(index == n){
        if(turn(word,n)){
            printed = 1;
        }
        word[index-1][1] = 0;
        return;
    }
    for(int i = 1;i<10;i++){
        word[index][1] = i;
        permutation(word,index+1,n);
    }
}

int main(){
    int table[26] = {};
    scanf("%s%s%s",a,b,c);
    int word[26][2] = {};
    int len = 0;
    for(int i = 0;i<strlen(a);i++){
        if(isupper(a[i])){
            table[a[i]-'A'] = 1;
        }
    }
    for(int i = 0;i<strlen(b);i++){
        if(isupper(b[i])){
            table[b[i]-'A'] = 1;
        }
    }
    for(int i = 0;i<strlen(c);i++){
        if(isupper(c[i])){
            table[c[i]-'A'] = 1;
        }
    }
    for(int i = 0;i<26;i++){
        if(table[i] == 1){
            word[len][0] = i+'A';
            word[len][1] = 0;
            len++;
        }
    }
    permutation(word,0,len);
    return 0;
}