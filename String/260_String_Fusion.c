#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char fullword[128] = {};
	char lineword[128] = {};
	scanf("%s",fullword);
	while(scanf("%s",lineword)!=EOF){
		int check_full = strlen(fullword)-1;
		int check_line = strlen(lineword)-1;
		while(fullword[check_full] != lineword[check_line] && check_line > -1){
			check_line --;
		}
		if(check_line == -1){
			strcat(fullword,lineword);
		}else{
			int find_eq_line = check_line;
			int find_eq_full = check_full;
			int same_value = ;
			while(fullword[find_eq_full] == lineword[find_eq_line] && find_eq_line > -1){
				find_eq_line--;find_eq_full--;same_value++;
			}
			if(same_value < check_line){
				strcat(fullword,lineword);
			}else{
				strcat(fullword,lineword+same_value);
			}
		}
	}
	printf("%s\n",fullword);
}
