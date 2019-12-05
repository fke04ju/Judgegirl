#include <stdio.h>
#include <stdlib.h>
#define MAXN 4096

int min(int a,int b){
    return ((a > b) ? b : a);
}

int main(){
    FILE *fp1,*fp2,*fout;
    char string1[128],string2[128],string3[128];
    scanf("%s%s%s",string1,string2,string3);
    fp1 = fopen(string1,"rb");
    fp2 = fopen(string2,"rb");
    fout = fopen(string3,"wb");
    fseek(fp1,0,SEEK_END);
    fseek(fp2,0,SEEK_END);
    long len_1 = ftell(fp1);
    long len_2 = ftell(fp2);
    if(len_1 < len_2){
        long tmp = len_1;
        len_1 = len_2;
        len_2 = tmp;
        FILE *tmp1 = fp1;
        fp1 = fp2;
        fp2 = tmp1;
    }
    fseek(fout,len_1,SEEK_SET);
    long add = 0;
    unsigned char bit1[MAXN] = {};
    unsigned char bit2[MAXN] = {};
    while(len_1 > 0 && len_2 > 0){
        int n = min(min(len_1,len_2),MAXN);
        fseek(fp1,-n,SEEK_CUR);
        fread(bit1,sizeof(unsigned char),n,fp1);
        fseek(fp2,-n,SEEK_CUR);
        fread(bit2,sizeof(unsigned char),n,fp2);
        fseek(fp1,-n,SEEK_CUR);
        fseek(fp2,-n,SEEK_CUR);
        for(int i = n-1;i>=0;i--){
            long a = bit1[i];
            bit1[i] = add+a;
            add = (bit1[i]<a);
            a = bit2[i];
            bit1[i] = bit1[i]+a;
            add |= (bit1[i]<a);
        }
        fseek(fout,-n,SEEK_CUR);
        fwrite(bit1,sizeof(unsigned char),n,fout);
        fseek(fout,-n,SEEK_CUR);
        len_1 -= n;
        len_2 -= n;
    }
    while(len_1){
        int n = min(len_1,MAXN);
        fseek(fp1,-n,SEEK_CUR);
        fread(bit1,sizeof(unsigned char),n,fp1);
        fseek(fp1,-n,SEEK_CUR);
        for(int i = n-1;i>=0;i--){
            long a = bit1[i];
            bit1[i] = a+add;
            add = (bit1[i]<a);
        }
        fseek(fout,-n,SEEK_CUR);
        fwrite(bit1,sizeof(unsigned char),n,fout);
        fseek(fout,-n,SEEK_CUR);
        len_1 -= n;
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fout);
}