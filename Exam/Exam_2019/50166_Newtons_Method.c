#include <stdio.h>
#include <stdlib.h>
 
double func[10];
double slope[10];
int mult[10];
 
int main(){
    int d;
    int cnt = 0;
    scanf("%d",&d);
    for(int i = d;i>=0;i--){
        mult[cnt] = i;
        cnt++;
    }
    int a;
    for(int i = 0;i<d+1;i++){
        scanf("%lf",&func[i]);
        slope[i] = func[i]*mult[i];
    }
    scanf("%d",&a);
    double x1;
    scanf("%lf",&x1);
    //x2 = x1-f(x1)/f'(x1)
    for(int i = 0;i<a;i++){
        double fx1 = 0;
        double fpx1 = 0;
        for(int j = 0;j<d+1;j++){
            double tmp = func[j];
            for(int k = 0;k<mult[j];k++){
                tmp *= x1;
            }
            fx1 += tmp;
        }
        for(int j = 0;j<d;j++){
            double tmp = slope[j];
            for(int k = 0;k<mult[j+1];k++){
                tmp *= x1;
            }
            fpx1 += tmp;
        }
        printf("%.4lf %.4lf\n",x1,fx1);
        x1 -= (fx1/fpx1);
    }
}