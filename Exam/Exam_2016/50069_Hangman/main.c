#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"



int main(){
    int n;
    scanf("%d",&n);
    char q[MAXL];
    char g[MAXL];
    int G;
    for(int i = 0;i<n;i++){
        scanf("%s%d%s",q,&G,g);
        int l = strlen(g);
        int printed = 0;
        Hangman *game = newGame(q,G);
        for(int j = 0;j<l;j++){
            int stat = guess(game,g[j]);
            if(stat == -1){
                printf("-1 ");
                printStatus(game);
                printf("You Lose\n");
                printed = 1;
                break;
            }else if(stat == 0){
                printf("0 ");
                printStatus(game);
            }else{
                printf("1 ");
                printStatus(game);
            }
            if(solved(game) == 1){
                printf("You Win\n");
                printed = 1;
                break;
            }
        }
        if(printed == 0){
            printf("You Quit\n");
        }
    }
}