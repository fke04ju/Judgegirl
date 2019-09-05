#include <stdio.h>
#include "eval.h"
 
int eval(int exp[]) {
    int new[exp[0]];
    new[0] = exp[1];
    int len = 1;
    for(int i = 2;i<exp[0];i+=2){
        if(exp[i] == 1){
            new[len] = exp[i];
            new[len+1] = exp[i+1];
            len+=2;
        }else if(exp[i] == 2){
            new[len] = exp[i];
            new[len+1] = exp[i+1];
            len+=2;
        }else if(exp[i]== 3){
            new[len-1] = new[len-1]*exp[i+1];
        }else if(exp[i]== 4){
            if(exp[i+1] == 0){
                return -2147483647;
            }else{
                new[len-1] = new[len-1]/exp[i+1];
            }
        }else{
            return -2147483646;
        }
    }
    int ans = new[0];
    for(int i = 1;i<len;i+=2){
        if(new[i] == 1){
            ans += new[i+1];
        }else{
            ans -= new[i+1];
        }
    }
    return ans;
}