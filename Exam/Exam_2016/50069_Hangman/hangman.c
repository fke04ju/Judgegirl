#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

struct Hangman{
    char ans[MAXL];
    char ques[MAXL];
    int G;
    int tmpG;
    int len;
};
typedef struct Hangman Hangman;
 
Hangman* newGame(char *answer, int G){
    Hangman *tmp = (Hangman *)malloc(sizeof(Hangman));
    tmp->G = G;
    strcpy(tmp->ans,answer);
    strcpy(tmp->ques,answer);
    tmp->len = strlen(answer);
    for(int i = 0;i<tmp->len;i++){
        tmp->ques[i] = '*';
    }
    tmp->tmpG = 0;
    return tmp;
}
int guess(Hangman* hangman, char ch){
    int find = 0;
    for(int i = 0;i<hangman->len;i++){
        if(ch == hangman->ans[i]){
            if(hangman->ques[i] == '*'){
                hangman->ques[i] = ch;
            }
            find = 1;
        }
    }
    if(find == 0){
        hangman->tmpG++;
        if(hangman->tmpG < hangman->G){
            return 0;
        }else{
            return -1;
        }
    }else{
        return 1;
    }
}
void printStatus(Hangman* hangman){
    printf("%s",hangman->ques);
    puts("");
    return;
}
int solved(Hangman* hangman){
    if(!strcmp(hangman->ques,hangman->ans)){
        return 1;
    }else{
        return 0;
    }
}