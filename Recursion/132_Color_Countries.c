#include <stdio.h>
#include <stdlib.h>
int n,c,p;
int country[20] = {};
int adj[20][20] = {};
int check = 0;

int check_color(int index){
	for(int i = 0;i<n;i++){
		if(adj[index][i] == 1 && country[i] == country[index]){
			return 0;
		}
	}
	return 1;
}

void color(int len){
	if(len == n && check == 0){
		for(int i = 0;i<n;i++){
			printf("%d\n",country[i]);
		}
		check = 1;
		return;
	}
	if(check == 0){
		for(int i = 1;i<=c;i++){
			country[len] = i;
			if(check_color(len) == 1){
				color(len+1);
			}
			country[len] = 0;
		}
	}
}

int main(){
	int index,place;
	scanf("%d%d%d",&n,&c,&p);
	for(int i = 0;i<p;i++){
		scanf("%d%d",&index,&place);
		adj[index][place]++;
		adj[place][index]++;
	}
	color(0);
	if(check == 0){
		printf("no solution.\n");
	}
}
