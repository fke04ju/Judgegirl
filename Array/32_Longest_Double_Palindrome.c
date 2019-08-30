#include <stdio.h>
/*
 
1    i=0           , i=1           , i=2           , ... , i=n-2         , i=n-1
    ## We need these 2 index
2    start         , start+1       , start+2       , ... , start+length-2, start+length-1
3    start+length-1, start+length-2, start+length-3, ... , i=1           , i=0
 
 
    Exercise:
    i=x;
1    i=x;
2    start+x
3    start+length-x-1
 
*/
int is_palindrome(int start,int length,int word[]){
    for(int i = 0;i < length;i++){
        if(word[start+i] != word[length+start-i-1]){
            return 0;
        }
    }
    return 1;
}
 
int main () {
    int word[100];
    int count = 0;
    while(scanf("%d",&word[count])!=EOF){
        count++;
    }
    int first_start = 0;
    int max = 0;
    for(int i = 0;i<count;i++){
        for(int j = 1;j<count-i;j++){
            if(is_palindrome(i,j,word) == 1){
                for(int k = 1;k<count-i-j+1;k++){
                    if(is_palindrome(i+j,k,word)){
                        int jerry = j+k;
                        int sophia = i;
                        if(max<=jerry){
                            max = jerry;
                            first_start = sophia;
                        }
                    }
                }
            }
        }
    }
    for(int l=first_start;l<first_start+max;l++)
        printf("%d%s",word[l], l == first_start+max-1 ? "" : " ");
}