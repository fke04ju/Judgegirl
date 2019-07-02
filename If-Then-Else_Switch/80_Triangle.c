#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	int x1,y1,x2,y2,x3,y3,a,b,c,t;
    	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    	a = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    	b = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
    	c = (x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    	if(a < b){
			t = b;
			b = a;
			a = t;
		}
	    if(a < c){
			t = c;
			c = a;
			a = t;
		}
    	if(b < c){
			t = c;
			c = b;
			b = t;
		}
    	if(a == b || b == c || a == c){
			printf("isosceles");
		}else if(a == (b+c)){
			printf("right")
		}else if(a <= (b+c)){
			printf("acute");
		}else{
			printf("obtuse");
		}
    	printf("\n");
    }
}
