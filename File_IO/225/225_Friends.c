#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct person{
	unsigned int id;
	char name[32];
};

struct friends{
	unsigned id1;
	unsigned id2;
};

int main(){
	FILE *fp;
	fp = fopen("friends","rb");
	int p[2],f[2];
	fread(p,sizeof(int),1,fp);
	struct person p_arr[p[0]];
	fread(p_arr,sizeof(struct person),p[0],fp);
	fread(f,sizeof(int),1,fp);
	struct friends f_arr[f[0]];
	fread(f_arr,sizeof(struct friends),f[0],fp);
	fclose(fp);
	char name1[32],name2[32];
	while(scanf("%s",name1)!=EOF){
		if(!strcmp(name1,"end")){
			return 0;
		}else{
			int id_1,id_2;
			scanf("%s",name2);
			for(int i = 0;i<p[0];i++){
				if(!strcmp(name1,p_arr[i].name)){
					id_1 = p_arr[i].id;
				}
				if(!strcmp(name2,p_arr[i].name)){
					id_2 = p_arr[i].id;
				}
			}
			int check = 0;
			for(int i = 0;i<f[0] && !check;i++){
				if(f_arr[i].id1 == id_1){
					if(f_arr[i].id2 == id_2){
						printf("yes\n");
						check = 1;
					}
				}else if(f_arr[i].id2 == id_1){
					if(f_arr[i].id1 == id_2){
						printf("yes\n");
						check = 1;
					}
				}
			}
			if(!check){
				printf("no\n");
			}
		}
	}
}
