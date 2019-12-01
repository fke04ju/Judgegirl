#include "expression.h"
#include <string.h>

char newstring[1000000];
int length;
int error;

int myexpression(){
    if(newstring[length] == '-'){
        length ++;
        return -myexpression();
    }
    if(newstring[length] == '('){
        length ++;
        int a = myexpression();
        char operation = newstring[length++];
        int b = myexpression();
        length++;
        if(operation == '+'){
            return a+b;
        }else if(operation == '-'){
            return a-b;
        }else if(operation == '*'){
            return a*b;
        }else if(operation == '/'){
            if(b == 0){
                error = 1;
                return 0;
            }else{
                return a/b;
            }
        }
    }
    if(newstring[length] <= '9' && newstring[length] >= '0'){
        return newstring[length++]-'0';
    }else{
        error = 1;
        return 0;
    }
}

int expression(char *string){
    strcpy(newstring,string);
    length = 0;
    error = 0;
    int ret = myexpression();
    if(error == 1 || newstring[length] != '\0'){
        return -2147483648;
    }
    return ret;
}