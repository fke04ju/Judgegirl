#include <stdio.h>

int gcd(int t,int v){
	if(t%v == 0){
		return v;
	}else{
		return gcd(v,t%v);
	}
}

int main(){
	int pins[16][16][2] = {};
	int ratio[16][17][2] = {};
	int n;
	scanf("%d",&n);
	if(n == 0){
		printf("1/1\n");
		return 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			scanf("%d%d",&pins[i][j][0],&pins[i][j][1]);
		}
	}
	for(int i = 1;i<=n;i++){
		int total = 0;
		int left_up = 1,left_down = 1;
		for(int j = 0;j<i;j++){
			if(i == 1){
				total = pins[i][j][0]+pins[i][j][1];
				int gcd_0 = gcd(pins[i][j][0],total);
				int gcd_1 = gcd(pins[i][j][1],total);
				ratio[i][0][0] = pins[i][j][0]/gcd_0;
				ratio[i][0][1] = total/gcd_0;
				ratio[i][1][0] = pins[i][j][1]/gcd_1;
				ratio[i][1][1] = total/gcd_1;
			}else{
				int tmp_up = ratio[i][j][0];
				int tmp_down = ratio[i][j][1];
				total = pins[i][j][0]+pins[i][j][1];
				int gcd_0 = gcd(pins[i][j][0],total);
				int gcd_1 = gcd(pins[i][j][1],total);
				ratio[i][j][0] = pins[i][j][0]/gcd_0;
				ratio[i][j][1] = total/gcd_0;
				ratio[i][j+1][0] = pins[i][j][1]/gcd_1;
				ratio[i][j+1][1] = total/gcd_1;
//				printf("ok\n");
				int mult_up_1 = ratio[i][j][0] * ratio[i-1][j][0];
				int mult_down_1 = ratio[i][j][1] * ratio[i-1][j][1];
				int mult_up_2 = ratio[i][j+1][0] * ratio[i-1][j][0];
				int mult_down_2 = ratio[i][j+1][1] * ratio[i-1][j][1];
				int gcd_0_0 = gcd(mult_up_1,mult_down_1);
				int gcd_0_1 = gcd(mult_up_2,mult_down_2);
				ratio[i][j][0] = mult_up_1/gcd_0_0;
				ratio[i][j][1] = mult_down_1/gcd_0_0;
				ratio[i][j+1][0] = mult_up_2/gcd_0_1;
				ratio[i][j+1][1] = mult_down_2/gcd_0_1;
				if(j != 0){
					ratio[i][j][0]*=tmp_down;
					tmp_up *= ratio[i][j][1];
					ratio[i][j][1]*=tmp_down;
					ratio[i][j][0]+=tmp_up;
					int gcd__ = gcd(ratio[i][j][0],ratio[i][j][1]);
					ratio[i][j][0] /= gcd__;
					ratio[i][j][1] /= gcd__;
				}
//				printf("%d %d %d %d %d/%d %d/%d\n",gcd_0,gcd_1,gcd_0_0,gcd_0_1,mult_up_1,mult_down_1,mult_up_2,mult_down_2);
			}
//			printf("%d/%d  %d/%d\n",ratio[i][j][0],ratio[i][j][1],ratio[i][j+1][0],ratio[i][j+1][1]);
		}
	}
	for(int i = 0;i<=n;i++){
		printf("%d/%d\n",ratio[n][i][0],ratio[n][i][1]);
	}
}
