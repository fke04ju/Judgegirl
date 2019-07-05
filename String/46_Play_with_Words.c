#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char command[10],where[10],which[2],c;
	char word_1[50050] = {},word_2[50050] = {};
	char invalid[50050] = {};
	char alphatable[50050] = {};
	int numtable[50050] = {};
	for(int i = 0;i<50050;i++){
		invalid[i] = '\0';
		word_1[i] = '\0';
		word_2[i] = '\0';
	}
	int wh;
	while(scanf("%s",command)!=EOF){
		if(command[0] == 'i'){ // insert
			scanf("%s%s",where,which);
			if(where[0] == 'l'){
				strcpy(word_2,word_1);
				strcpy(word_1,which);
				strcat(word_1,word_2);
			}else if(where[0] == 'r'){
				strcat(word_1,which);
			}else{
				wh = atoi(where);
				if(wh == 1){
					strcpy(word_2,word_1);
					strcpy(word_1,which);
					strcat(word_1,word_2);
				}else if(wh-1 == strlen(word_1)){
					strcat(word_1,which);
				}else{
					strcpy(word_2,invalid);
					strncat(word_2,word_1,wh-1);
					strcat(word_2,which);
					strncat(word_2,word_1+wh-1,strlen(word_1)-wh+1);
					strcpy(word_1,word_2);
				}
			}
		}else{
			scanf("%s",where);
			if(where[0] == 'l'){
				strcpy(word_2,invalid);
				strncat(word_2,word_1+1,strlen(word_1)-1);
				strcpy(word_1,word_2);
			}else if(where[0] == 'r'){
				strcpy(word_2,invalid);
				strncat(word_2,word_1,strlen(word_1)-1);
				strcpy(word_1,word_2);
			}else{
				wh = atoi(where);
				if(wh == 1){
					strcpy(word_2,invalid);
					strncat(word_2,word_1+1,strlen(word_1)-1);
					strcpy(word_1,word_2);
				}else if(wh == strlen(word_1)){
					strcpy(word_2,invalid);
					strncat(word_2,word_1,wh-1);
					strcpy(word_1,word_2);
				}else{
					strcpy(word_2,invalid);
					strncat(word_2,word_1,wh-1);
					strncat(word_2,word_1+wh,strlen(word_1)-wh+1);
					strcpy(word_1,word_2);
				}
			}
		}
//		printf("%s\n",word_1);
	}
//	printf("%s\n",word_1);
	int prev = 0;
	int n = 1;
	int count = 1;
	int another_c = 0;
	int max = 0;
	while(n < strlen(word_1)){
		while(word_1[n] == word_1[prev]){
			count ++;
			n++;
		}
		if(max < count){
			max = count;
		}
		alphatable[another_c] = word_1[prev];
		numtable[another_c] = count;
		another_c++;
		count = 1;
		n++;
		prev = n-1;
	}
	if(strlen(word_1) > 0){
		alphatable[another_c] = word_1[prev];
		numtable[another_c] = count;
		another_c++;
		if(count > max){
			max = count;
		}
	}
	for(int i = 0;i<another_c;i++){
		if(numtable[i] == max){
			printf("%c ",alphatable[i]);
		}
	}
	printf("%d\n",max);
}
