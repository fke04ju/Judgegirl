#include <stdio.h>

int end_file(int arr[],int n){
    int ch = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 1){
            ch ++;
        }
    }
    if(ch == n){
        return 0;
    }else{
        return 1;
    }
}

int find_min(int arr[],int end[],int n){
    int min = 2147483647;
    int index = 0;
    for(int i = 0;i<n;i++){
        if(end[i] == 0){
            if(min > arr[i]){
                min = arr[i];
                index = i;
            }
        }
    }
    printf("%d\n",min);
    return index;
}

int main(){
    int n;
    scanf("%d",&n);
    FILE *fp[n];
    char name[20];
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%s",name);
        fp[i] = fopen(name,"r");
        fread(arr+i,sizeof(int),1,fp[i]);
    }
    int end[n];
    for(int i = 0;i<n;i++){
        end[i] = 0; // 1=end;
    }
    while(end_file(end,n)){
        int min_index = find_min(arr,end,n);
        if(fread(arr+min_index,sizeof(int),1,fp[min_index]) == 0){
            end[min_index] = 1;
        }
    }
    for(int i = 0;i<n;i++){
        fclose(fp[i]);
    }
}