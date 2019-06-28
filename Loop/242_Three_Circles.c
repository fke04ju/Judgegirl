#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long int cir1_x,cir1_y,cir1_r;
    long long int cir2_x,cir2_y,cir2_r;
    long long int cir3_x,cir3_y,cir3_r;
    while(n--){
        int count = 0;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&cir1_x,&cir1_y,&cir1_r,&cir2_x,&cir2_y,&cir2_r,&cir3_x,&cir3_y,&cir3_r);
        for(int j = cir1_x-cir1_r;j<=cir1_x+cir1_r;j++){
            for(int k = cir1_y-cir1_r;k<=cir1_y+cir1_r;k++){
                if(((j-cir1_x)*(j-cir1_x)+(k-cir1_y)*(k-cir1_y))<=(cir1_r*cir1_r) && ((j-cir2_x)*(j-cir2_x)+(k-cir2_y)*(k-cir2_y))<=(cir2_r*cir2_r) && ((j-cir3_x)*(j-cir3_x)+(k-cir3_y)*(k-cir3_y))<=(cir3_r*cir3_r)){
                    count++;
                }
            }
        }
//        printf("%d\n",count);
        for(int j = cir1_x-cir1_r;j<=cir1_x+cir1_r;j++){
            for(int k = cir1_y-cir1_r;k<=cir1_y+cir1_r;k++){
                if(((j-cir1_x)*(j-cir1_x)+(k-cir1_y)*(k-cir1_y))<=(cir1_r*cir1_r) && ((j-cir2_x)*(j-cir2_x)+(k-cir2_y)*(k-cir2_y))>(cir2_r*cir2_r) && ((j-cir3_x)*(j-cir3_x)+(k-cir3_y)*(k-cir3_y))>(cir3_r*cir3_r)){
                    count++;
                }
            }
        }
//        printf("%d\n",count);
        for(int j = cir2_x-cir2_r;j<=cir2_x+cir2_r;j++){
            for(int k = cir2_y-cir2_r;k<=cir2_y+cir2_r;k++){
                if(((j-cir1_x)*(j-cir1_x)+(k-cir1_y)*(k-cir1_y))>(cir1_r*cir1_r) && ((j-cir2_x)*(j-cir2_x)+(k-cir2_y)*(k-cir2_y))<=(cir2_r*cir2_r) && ((j-cir3_x)*(j-cir3_x)+(k-cir3_y)*(k-cir3_y))>(cir3_r*cir3_r)){
                    count++;
                }
            }
        }
//        printf("%d\n",count);
        for(int j = cir3_x-cir3_r;j<=cir3_x+cir3_r;j++){
            for(int k = cir3_y-cir3_r;k<=cir3_y+cir3_r;k++){
                if(((j-cir1_x)*(j-cir1_x)+(k-cir1_y)*(k-cir1_y))>(cir1_r*cir1_r) && ((j-cir2_x)*(j-cir2_x)+(k-cir2_y)*(k-cir2_y))>(cir2_r*cir2_r) && ((j-cir3_x)*(j-cir3_x)+(k-cir3_y)*(k-cir3_y))<=(cir3_r*cir3_r)){
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
 
}
