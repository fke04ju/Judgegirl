#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char plates[2][32][10] = {};
int p[2] = {};
int alp[26] = {};
int ALP[26] = {};
int dig[10] = {};
char word[10];
char newword[10];

void check(int which){
    int digsum = 0;
    for(int i = 1;i<7;i++){
        if(word[i-1] == '4' && word[i] == '4'){
            return;
        }
    }
    for(int i = 0;i<6;i++){
        if(newword[i] >= '0' && newword[i] <= '9'){
            digsum += (newword[i]-'0');
            dig[newword[i]-'0']++;
        }else if(newword[i] <= 'Z' && newword[i] >= 'A'){
            ALP[newword[i]-'A']++;
        }else if(newword[i] <= 'z' && newword[i] >= 'a'){
            alp[newword[i]-'a']++;
        }else{
            return;
        }
    }
    if(digsum%7 == 0){
        return;
    }
    for(int i = 0;i<26;i++){
        if(ALP[i] > 2 || alp[i] > 2){
            return;
        }
    }
    for(int i = 0;i<10;i++){
        if(dig[i] > 2){
            return;
        }
    }
    strcpy(plates[which][p[which]],word);
    p[which]++;
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",word);
        if(word[2] == '-'){
            int cnt = 0;
            for(int i = 0;i<7;i++){
                if(i != 2){
                    newword[cnt] = word[i];
                    cnt++;
                }
            }
            check(0);
        }else if(word[3] == '-'){
            int cnt = 0;
            for(int i = 0;i<7;i++){
                if(i != 3){
                    newword[cnt] = word[i];
                    cnt++;
                }
            }
            check(1);
        }
        for(int i = 0;i<26;i++){
            ALP[i] = 0;
            alp[i] = 0;
        }
        for(int i = 0;i<10;i++){
            dig[i] = 0;
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<p[i];j++){
            for(int k = j;k<p[i];k++){
                if(strcmp(plates[i][k],plates[i][j]) < 0){
                    char tmp[10];
                    strcpy(tmp,plates[i][k]);
                    strcpy(plates[i][k],plates[i][j]);
                    strcpy(plates[i][j],tmp);
                }
            }
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<p[i];j++){
            printf("%s\n",plates[i][j]);
        }
    }
}