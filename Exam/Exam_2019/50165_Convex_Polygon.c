#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    double arr[250][3] = {};
    for(int i = 0;i<n;i++){
        scanf("%lf%lf%lf",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    double ans = 0;
    double point[250][2] = {};
    double m,c,y,x;
    for(int i = 1;i<n;i++){
        m = arr[i-1][1] * arr[i][0] / arr[i-1][0] - arr[i][1];
        c = arr[i-1][2] * arr[i][0] / arr[i-1][0] - arr[i][2];
        y = c/m;
        x = (arr[i-1][2] - arr[i-1][1] * y) / arr[i-1][0];
        point[i-1][0] = x;
        point[i-1][1] = y;
    }
    m = arr[n-1][1] * arr[0][0] / arr[n-1][0] - arr[0][1];
    c = arr[n-1][2] * arr[0][0] / arr[n-1][0] - arr[0][2];
    y = c/m;
    x = (arr[n-1][2] - arr[n-1][1] * y) / arr[n-1][0];
    point[n-1][0] = x;
    point[n-1][1] = y;
    for(int i = 0;i<n;i++){
        ans += sqrt((point[i%n][0]-point[(i+1)%n][0])*(point[i%n][0]-point[(i+1)%n][0])+(point[i%n][1]-point[(i+1)%n][1])*(point[i%n][1]-point[(i+1)%n][1]));
    }
    printf("%.3lf\n",ans);
}