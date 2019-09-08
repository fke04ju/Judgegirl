#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fs.h"

int cmp(const void *data1,const void *data2){
    return strcmp(((Account *)data1)->name, ((Account *)data2)->name);
}

int check(Account *tmp){
    if(tmp->balance < 0){
        return 0;
    }
    if(tmp->gender != 0 && tmp->gender != 1){
        return 0;
    }
    for(int i = 0;i<strlen(tmp->name);i++){
        if(!isalpha(tmp->name[i]) && tmp->name[i] != ' '){
            return 0;
        }
    }
    return 1;
}

Account account[65536];

int main(){
    Account tmp;
    char in[128],out[128];
    scanf("%s%s",in,out);
    FILE *fp,*fout;
    fp = fopen(in,"rb");
    fout = fopen(out,"wb");
    int len = 0;
    while(fread(&tmp,sizeof(Account),1,fp) == 1){
        if(check(&tmp) == 1){
            account[len] = tmp;
            len++;
        }
    }
    qsort(account,len,sizeof(Account),cmp);
    fwrite(account,sizeof(Account),len,fout);
    fclose(fp);
    fclose(fout);
}