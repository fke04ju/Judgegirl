#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word[100100] = {};

void replace_word(char which,char to){
    int len = strlen(word);
    for(int i = 0;i<len;i++){
        if(word[i] == which){
            word[i] = to;
        }
    }
    return;
}

void remove_word(char which){
    int len = strlen(word);
    char tmp[100100] = {};
    int i;
    for(i = 0;i<len;i++){
        if(word[i] == which){
            strncpy(tmp,word+i,len-i);
            strcpy(word+i,tmp+1);
            i--;
        }
    }
    return;
}

int main(){
    char command[100100] = {};
    char c1[2],c2[2];
    char which,to;
    char tmp[100100] = {};
    char null[100100] = {};
    scanf("%s",word);
    while(scanf("%s",command)!=EOF){
        if(!strcmp(command,"end")){
            printf("%s\n",word);
            return 0;
        }else{
            if(!strcmp(command,"replace")){
                scanf("%s%s",c1,c2);
                which = c1[0];
                to = c2[0];
                replace_word(which,to);
            }else if(!strcmp(command,"remove")){
                scanf("%s",c1);
                which = c1[0];
                remove_word(which);
            }else if(!strcmp(command,"addhead")){
                scanf("%s",c1);
                which = c1[0];
                tmp[0] = which;
                strcat(tmp,word);
                strcpy(word,tmp);
                int len_tmp = strlen(tmp);
                for(int i = 0;i<len_tmp;i++){
                    tmp[i] = '\0';
                }
            }else if(!strcmp(command,"addtail")){
                scanf("%s",c1);
                c1[1] = '\0';
                strcat(word,c1);
            }else{
                printf("invalid command %s\n",command);
                return 0;
            }
        }
    }
}