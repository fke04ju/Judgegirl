#include <stdio.h>
int main(){
    int x;
    int score=0;
    scanf("%d",&x);
    if(x<=0){
		score=-100;
	}else{
    	if(x%3==0){
        	score+=3;
    	}
    	if(x%5==0){
        	score+=5;
    	}
    	if(100<=x && x<=200){
        	score+=50;
    	}else{
        	score-=50;
    	}
    }
    printf("%d",score);
}
