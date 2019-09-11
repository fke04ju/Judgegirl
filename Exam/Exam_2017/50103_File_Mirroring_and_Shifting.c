#include <stdio.h>

int main(){
    char input[17],output[17];
    int n;
    scanf("%s%s%d",input,output,&n);
    FILE *fp,*fout;
    fp = fopen(input,"rb");
    fout = fopen(output,"wb");
    fseek(fp,0,SEEK_END);
    int total_number = ftell(fp);
    unsigned char num;
    for(int i = 0;i<total_number;i++){
        fseek(fp,-((n+i)%total_number+1),SEEK_END);
        fread(&num,sizeof(char),1,fp);
        unsigned char tmp = 0;
        for(int j = 0;j<8;j++){
            if(num & (1 << j)){
                tmp |= (1 << (7-j));
            }
        }
        fwrite(&tmp,sizeof(char),1,fout);
    }
    fclose(fp);
    fclose(fout);
}