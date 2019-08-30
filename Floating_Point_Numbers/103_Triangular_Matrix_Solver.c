#include <stdio.h>
double fnc[16][16];
double ans[16];
double solution[16];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%lf",&fnc[i][j]);
        }
    }
    for(int i  = 0;i<n;i++){
        scanf("%lf",&ans[i]);
    }
    solution[n-1] = ans[n-1]/fnc[n-1][n-1];
    for(int i = n-2;i>=0;i--){
        double ansn=0;
        for(int j = i+1;j<n;j++){
            ansn-=fnc[i][j]*solution[j];
        }
        solution[i] = (ans[i]+ansn)/fnc[i][i];
    }
    for(int i = 0;i<n;i++){
        printf("%.6lf\n",solution[i]);
    }
}