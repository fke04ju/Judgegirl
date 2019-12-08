#include <stdio.h>

struct P0{
    int pi;
};

struct P1{
    char pc[4];
};

typedef struct ins{
    int type;
    union{
        struct P0 p0;
        struct P1 p1; 
    }parameter;
}instruction;

int main(){
    FILE *fp;
    char string[20];
    scanf("%s",string);
    fp = fopen(string,"rb");
    instruction ins;
    while(1){
        int status = fread(&ins,sizeof(instruction),1,fp);
        if(status != 1){
            printf("Seek end\n");
            break;
        }
        if(ins.type == 0){
            printf("%d",ins.parameter.p0.pi);
        }else if(ins.type == 1){
            printf("%c%c%c%c",ins.parameter.p1.pc[0],ins.parameter.p1.pc[1],ins.parameter.p1.pc[2],ins.parameter.p1.pc[3]);
        }else if(ins.type == 2){
            char c;
            while(fread(&c,sizeof(char),1,fp) && c){
                printf("%c",c);
            }
        }else if(ins.type == 3){
            fseek(fp,-sizeof(instruction),SEEK_CUR);
            fseek(fp,ins.parameter.p0.pi,SEEK_CUR);
        }else if(ins.type == 4){
            fseek(fp,ins.parameter.p0.pi,SEEK_SET);
        }else if(ins.type == 5){
            fseek(fp,ins.parameter.p0.pi,SEEK_END);
        }else{
            printf("Seek end\n");
            break;
        }
    }
}