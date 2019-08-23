#include <stdio.h>
#include <stdlib.h>
int n,m;
char name[10][65];
int bingoboard[655361] = {};
int location[5140] = {};
int bingoplace[65537][10][2] = {};
int bingo[10] = {};
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%s",name[i]);
        for(int j = 0;j<m;j++){
            for(int k = 0;k<m;k++){
                scanf("%d",&bingoboard[i*m*m+j*m+k]);
				bingoplace[bingoboard[i*m*m+j*m+k]][i][0] = j;
				bingoplace[bingoboard[i*m*m+j*m+k]][i][1] = k;
            }
        }
    }
    int step;
    int flag = 0;
    int check;
	int place;
    while(1){
        scanf("%d",&step);
		for(int i = 0;i<n;i++){
			place = i*m*m+bingoplace[step][i][0]*m+bingoplace[step][i][1];
			bingoboard[place] = 0;
			location[i*(2*m+2)+bingoplace[step][i][0]] ++;
			location[i*(2*m+2)+m+bingoplace[step][i][1]]++;
			if(bingoplace[step][i][0] == bingoplace[step][i][1]){
				location[i*(2*m+2)+2*m] ++;
			}
			if(bingoplace[step][i][0] == m-1-bingoplace[step][i][1]){
				location[i*(2*m+2)+2*m+1] ++;
			}
		}
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2*m+2;j++){
                if(location[i*(2*m+2)+j] == m){
                    bingo[i] = 1;
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            printf("%d",step);
            for(int i = 0;i<n;i++){
                if(bingo[i] == 1){
                    printf(" %s",name[i]);
                }
            }
            puts("");
            return 0;
        }
    }
}
