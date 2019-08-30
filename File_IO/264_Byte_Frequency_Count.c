#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXN 65536
 
int main(){
    FILE *file;
    char filename[210];
    scanf("%s",filename);
    file = fopen(filename,"rb");
    assert(file!=NULL);
    int n[5];
    fread(n,sizeof(int),1,file);
    int a[MAXN] = {};
    short s[20];
    while(fread(s,sizeof(short),1,file)){
        a[s[0]+32768]++;
    }
    fclose(file);
    int max = 0;
    int index = 0;
    for(int i = 0;i<MAXN;i++){
        if(max <= a[i] && index < i){
            max = a[i];
            index = i;
        }
    }
    printf("%d\n%d\n",index-32768,max);
}
