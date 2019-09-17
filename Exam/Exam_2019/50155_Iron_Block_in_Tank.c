#include <stdio.h>
 
int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int water_v = a*b*d;
    int metal_v = g*e*f;
    int serface = a*b;
    int total_v = a*b*c;
    if(d == 0){
        printf("0\n");
    }else{
        if(serface == (e*f)){
            if(g >= c){
                printf("0\n");
            }else{
                if(g+d >= c){
                    printf("%d\n",c);
                }else{
                    printf("%d\n",g+d);
                }
            }
        }else{
            if(water_v + metal_v <= total_v && (water_v+metal_v)/serface > g){
                printf("%d\n",(water_v+metal_v)/serface);
            }else{
                int after_serface = serface-(e*f);
                int after_v = after_serface*c;
                if(water_v > after_v){
                    printf("%d\n",c);
                }else{
                    printf("%d\n",water_v/after_serface);
                }
            }
        }
    }
    return 0;
}