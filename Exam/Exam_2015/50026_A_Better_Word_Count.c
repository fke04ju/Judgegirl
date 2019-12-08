#include <stdio.h>
#include <ctype.h>

int main(){
    char string[1050];
    scanf("%s",string);
    FILE *fp = fopen(string,"r");
    fseek(fp,0,SEEK_SET);
    char c;
    int is_new_line = 0;
    int cnt_lines = 0;
    int cnt_words = 0;
    int cnt_bytes = 0;
    int is_word = 0;
    while(1){
        int stat = fscanf(fp,"%c",&c);
        if(stat != 1){
            if(is_new_line == 1){
                cnt_words++;
                cnt_lines++;
            }
            break;
        }else if(c == '\n'){
            if(is_word == 1){
                is_word = 0;
                cnt_words++;
            }
            is_new_line = 0;
            cnt_lines++;
            cnt_bytes++;
        }else{
            if(!isalpha(c)){
                if(is_word == 1){
                    cnt_words ++;
                }
                is_word = 0;
            }else{
                is_word = 1;
            }
            is_new_line = 1;
            cnt_bytes++;
        }
    }
    printf("%d %d %d\n",cnt_lines,cnt_words,cnt_bytes);
}