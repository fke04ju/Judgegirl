#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int m;
	scanf("%d",&m);
	char arr[m][256];
	int whitespace[m];
	for(int i = 0;i<m;i++){
		for(int j = 0;j<m;j++){
			arr[i][j] = '\0';
		}
	}
	for(int i = 0;i<m;i++){
		whitespace[i] = 0;
	}
	int len = 0;
	int count = 0;
	char word[256];
	char output[256];
	char clear[256];
	for(int i = 0;i<256;i++){
		word[i] = '\0';
		output[i] = '\0';
		clear[i] = '\0';
	}
	while(scanf("%s",word)!=EOF){
		int word_len = strlen(word);
		if(count + word_len > m){
			if(len == 1){
				for(int i = 0;i<strlen(arr[0]);i++){
					printf("%c",arr[0][i]);
				}
				for(int i = strlen(arr[0]);i<m;i++){
					printf(" ");
				}
				puts("");
				strcpy(arr[0],clear);
				len = 0;
				count = 0;
			}else{
				int less = m-count+len;
				int spare = less/(len-1);
				int lost = less - (spare*(len-1));
				for(int i = 0;i<len-1;i++){
					if(i < lost){
						whitespace[i] += 1;
					}
					whitespace[i] += spare;
				}
				int l = 0;
				for(int i = 0;i<len;i++){
					for(int j = 0;j<strlen(arr[i]);j++){
						output[l] = arr[i][j];
						l++;
					}
					for(int j = 0;j<whitespace[i];j++){
						output[l] = ' ';
						l++;
					}
				}
				for(int i = 0;i<l;i++){
					printf("%c",output[i]);
				}
				puts("");
				strcpy(output,clear);
				for(int i = 0;i<len-1;i++){
					whitespace[i] = 0;
				}
				for(int i = 0;i<len;i++){
					strcpy(arr[i],clear);
				}
				len = 0;
				count = 0;
			}
		}
		strcpy(arr[len],word);
		count += word_len;
		count += 1;
		len++;	
	}
	if(len == 1 && strcmp(arr[0],clear)){
		for(int i = 0;i<strlen(arr[0]);i++){
			printf("%c",arr[0][i]);
		}
		for(int i = strlen(arr[0]);i<m;i++){
			printf(" ");
		}
		puts("");
		return 0;
	}
	int less = m-count+len;
	int spare = less/(len-1);
	int lost = less % (len-1);
	for(int i = 0;i<len-1;i++){
		if(i < lost){
			whitespace[i] += 1;
		}
		whitespace[i] += spare;
	}
	int l = 0;
	for(int i = 0;i<len;i++){
		for(int j = 0;j<strlen(arr[i]);j++){
			output[l] = arr[i][j];
			l++;
		}
		for(int j = 0;j<whitespace[i];j++){
			output[l] = ' ';
			l++;
		}
	}
	for(int i = 0;i<l;i++){
		printf("%c",output[i]);
	}
	puts("");
}
