#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct one{
    char lastname[100];
    char firstname[100];
    char ID[100];
    int salary;
    int age;
}SQL;
 
typedef struct print{
    char start[10];
    char select[9][15];
    char condition[15];
    char operator[3];
    char constant[100];
}cond;
 
/*
int print(SQL data[],cond dem[],int l,int k,int i,int count){
    if(dem[i].select[l][0] == 'l'){
        return data[k].lastname;
    }else if(dem[i].select[l][0] == 'f'){
        return data[k].firstname;
    }else if(dem[i].select[l][0] == 'I'){
        return data[k].ID;
    }else if(dem[i].select[l][0] == 's'){
        return data[k].salary;
    }else{
        return data[k].age;
    }
}
*/
int main(){
    int datanumber;
    scanf("%d", &datanumber);
    SQL data[datanumber];
    for(int i = 0;i<datanumber;i++){
        scanf("%s%s%s%d%d", data[i].lastname, data[i].firstname, data[i].ID, &data[i].salary, &data[i].age);
    }
    int demand;
    scanf("%d",&demand);
    cond dem;
    while(demand--){
        scanf("%s",dem.start);
        int count = 0;
        int flag = 0;
        for(int j = 0;j<10 && flag == 0;j++){
            scanf("%s",dem.select[j]);
            if(dem.select[j][0] == 'w'){
                flag = 1;
                count = j;
            }
        }
        scanf("%s%s%s",dem.condition,dem.operator,dem.constant);
        if(dem.condition[0] == 'l'){ // lastname
            if(dem.operator[0] == '!'){ // lastname !=
                for(int k = 0;k<datanumber;k++){
                    if(strcmp(data[k].lastname,dem.constant)){ // lastname != constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){ 
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else{ // lastname ==
                for(int k = 0;k<datanumber;k++){
                    if(!strcmp(data[k].lastname,dem.constant)){ // lastname == constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }
        }else if(dem.condition[0] == 'f'){ //firstname
            if(dem.operator[0] == '!'){ // firstname !=
                for(int k = 0;k<datanumber;k++){
                    if(strcmp(data[k].firstname,dem.constant)){ //firstname != constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else{ // firstname ==
                for(int k = 0;k<datanumber;k++){
                    if(!strcmp(data[k].firstname,dem.constant)){ // firstname == constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }
        }else if(dem.condition[0] == 'I'){ // ID
            if(dem.operator[0] == '!'){ //  ID !=
                for(int k = 0;k<datanumber;k++){
                    if(strcmp(data[k].ID,dem.constant)){ // ID != constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else{ //  ID ==
                for(int k = 0;k<datanumber;k++){
                    if(!strcmp(data[k].ID,dem.constant)){ // ID == constant
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }
        }else if(dem.condition[0] == 's'){  // salary
            if(dem.operator[0] == '='){ // salary ==
                for(int k = 0;k<datanumber;k++){
                    if(data[k].salary == atoi(dem.constant)){ // salary == integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else if(dem.operator[0] == '>'){ //salary > 
                for(int k = 0;k<datanumber;k++){
                    if(data[k].salary > atoi(dem.constant)){ // salary > integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else{ // salary < 
                for(int k = 0;k<datanumber;k++){
                    if(data[k].salary < atoi(dem.constant)){ // salary < integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }
        }else{ // age
            if(dem.operator[0] == '='){ // age ==
                for(int k = 0;k<datanumber;k++){
                    if(data[k].age == atoi(dem.constant)){ // age == integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else if(dem.operator[0] == '>'){ // age > 
                for(int k = 0;k<datanumber;k++){
                    if(data[k].age > atoi(dem.constant)){ // age > integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }else{ // age < 
                for(int k = 0;k<datanumber;k++){
                    if(data[k].age < atoi(dem.constant)){ // age < integer
                        for(int l = 0;l<count;l++){
                            if(dem.select[l][0] == 'l'){
                                printf("%s%c",data[k].lastname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'f'){
                                printf("%s%c",data[k].firstname,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'I'){
                                printf("%s%c",data[k].ID,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 's'){
                                printf("%d%c",data[k].salary,(l<count-1)?' ':'\n');
                            }else if(dem.select[l][0] == 'a'){
                                printf("%d%c",data[k].age,(l<count-1)?' ':'\n');
                            }
                        }
                    }
                }
            }
        }
    }
}