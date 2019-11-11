#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strings[55][15];
int alp_to_num[128];
int num[55][15];
int leader[3];
int member[3][55];
int mem_num[3];
int mean[3][15];
int N,L,R;

int min(int a,int b){
    return (a < b)?a:b;
}

int lexicog(int a,int b){
    if(strcmp(strings[leader[a]],strings[leader[b]]) < 0){
        return a;
    }else{
        return b;
    }
}

int find_min(int a,int b,int c){
    int minim = min(a,min(b,c));
    if(minim == a){
        if(minim == b){
            if(minim == c){
                return lexicog(0,lexicog(1,2));
            }else{
                return lexicog(0,1);
            }
        }else{
            if(minim == c){
                return lexicog(0,2);
            }else{
                return 0;
            }
        }
    }else if(minim == b){
        if(minim == c){
            return lexicog(1,2);
        }else{
            return 1;
        }
    }else{
        return 2;
    }
}

int dist(int a,int b){
    int distance = 0;
    for(int i = 0;i<L;i++){
        distance += abs(num[a][i]-num[b][i]);
    }
    return distance;
}

int compute_mean(int a,int b){
    int sum = 0;
    for(int i = 0;i<mem_num[a];i++){
        sum += num[member[a][i]][b];
    }
    return sum/mem_num[a];
}

int dist_mean(int a,int b){
    int distance = 0;
    for(int i = 0;i<L;i++){
        distance += abs(mean[a][i]-num[member[a][b]][i]);
    }
    return distance;
}

int main(){
    for(int i = 65;i<=90;i++){
        alp_to_num[i] = i;
    }
    scanf("%d%d%d",&N,&L,&R);
    for(int i = 0;i<N;i++){
        scanf("%s",strings[i]);
        for(int j = 0;j<strlen(strings[i]);j++){
            num[i][j] = alp_to_num[strings[i][j]];
        }
    }
    for(int i = 0;i<3;i++){
        leader[i] = i;
    }
    while(R--){
        for(int i = 0;i<3;i++){
            mem_num[i] = 0;
        }
        for(int i = 0;i<3;i++){
            member[i][mem_num[i]] = leader[i];
            mem_num[i] ++;
        }
        for(int i = 0;i<N;i++){
            if(leader[0] != i && leader[1] != i && leader[2] != i){
                int idx = find_min(dist(leader[0],i),dist(leader[1],i),dist(leader[2],i));
                member[idx][mem_num[idx]] = i;
                mem_num[idx] ++;
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<L;j++){
                mean[i][j] = compute_mean(i,j);
            }
        }
        for(int i = 0;i<3;i++){
            int min_d = 2147483647;
            int idx = 0;
            for(int j = 0;j<mem_num[i];j++){
                if(min_d > dist_mean(i,j)){
                    idx = j;
                    min_d = dist_mean(i,j);
                }
            }
            for(int j = 0;j<mem_num[i];j++){
                if(min_d == dist_mean(i,j)){
                    if(strcmp(strings[member[i][idx]],strings[member[i][j]]) > 0){
                        idx = j;
                    }
                }
            }
            leader[i] = member[i][idx];
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2-i;j++){
            if(strcmp(strings[leader[j]],strings[leader[j+1]]) > 0){
                int tmp = leader[j];
                leader[j] = leader[j+1];
                leader[j+1] = tmp;
            }
        }
    }
    for(int i = 0;i<3;i++){
        printf("%s\n",strings[leader[i]]);
    }
}