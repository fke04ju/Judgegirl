#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word[50];
    int cnt = 0;
    int star_len = 0;
    char last_alp;
    while(scanf("%s",word)!=EOF){
        if(cnt == 0){
            printf("%s\n",word);
            star_len += strlen(word)-1;
            last_alp = word[strlen(word)-1];
        }else if(cnt % 2 == 0){
            if(last_alp == word[0]){
                for(int i = 1;i<strlen(word);i++){
                    printf("%c",word[i]);
                }
                puts("");
            }else{
                puts("");
                for(int i = 0;i<star_len;i++){
                    printf("*");
                }
                printf("%s\n",word);
            }
            star_len += strlen(word)-1;
            last_alp = word[strlen(word)-1];
        }else{
            if(last_alp == word[0]){
                for(int i = 1;i<strlen(word);i++){
                    for(int j = 0;j<star_len;j++){
                        printf("*");
                    }
                    printf("%c",word[i]);
                    if(i < strlen(word)-1){
                        puts("");
                    }
                }
            }else{
                for(int i = 0;i<strlen(word);i++){
                    for(int j = 0;j<star_len;j++){
                        printf("*");
                    }
                    printf("%c",word[i]);
                    if(i < strlen(word)-1){
                        puts("");
                    }
                }
            }
            last_alp = word[strlen(word)-1];
        }
        cnt++;
    }
}