#include <stdio.h>
 
int find_max(int a,int b,int c,int n){
    if(a >= b){
        if(a >= c){//a>c>b
            if(a >= n){
                return 1;
            }else{
                return 0;
            }
        }else{//c>a>b
            if(c >= n){
                return 3;
            }else{
                return 0;
            }
        }
    }else{
        if(a>c){//b>a>c
            if(b>=n){
                return 2;
            }else{
                return 0;
            }
        }else{
            if(b >= c){//b>c>a
                return 2;
            }else{
                return 3;
            }
        }
    }
}
 
int main(){
    int A,B,C;
    int A_b,A_e,A_c,B_b,B_e,B_c,C_b,C_c,C_e,N;
    int sp_at_A = -1,sp_at_B = -1,sp_at_C = -1;
    int R,H,g;
    int attack_a,attack_b,attack_c;
    scanf("%d%d%d",&R,&H,&g);
    scanf("%d%d%d%d%d%d%d%d%d%d",&A_b,&A_e,&A_c,&B_b,&B_e,&B_c,&C_b,&C_e,&C_c,&N);
    int High = H;
    for(int r = 0;r<R;r++){
        attack_a = 0,attack_b = 0,attack_c = 0;
        if(r - sp_at_A >= A_c || sp_at_A == -1){
            if(r <= A_c){
                if(sp_at_A == -1){
                    attack_a = A_b;
                }else{
                    attack_a = A_b + A_e * (r - sp_at_A - A_c);
                }
            }else{
                if(sp_at_A == -1){
                    attack_a = A_b+A_e*(r-A_c);
                }else{
                    attack_a = A_b + A_e*(r - sp_at_A - A_c);
                }
            }
        }
        if(r - sp_at_B >= B_c || sp_at_B == -1){
            if(r <= B_c){
                if(sp_at_B == -1){
                    attack_b = B_b;
                }else{
                    attack_b = B_b + B_e * (r - sp_at_B - B_c);
                }
            }else{
                if(sp_at_B == -1){
                    attack_b = B_b + B_e * (r - B_c);
                }else{
                    attack_b = B_b + B_e * (r - sp_at_B - B_c);
                }
            }
        }
        if(r - sp_at_C >= C_c || sp_at_C == -1){
            if(r <= C_c){
                if(sp_at_C == -1){
                    attack_c = C_b;
                }else{
                    attack_c = C_b + C_e * (r - sp_at_C - C_c);
                }
            }else{
                if(sp_at_C == -1){
                    attack_c = C_b + C_e * (r - C_c);
                }else{
                    attack_c = C_b + C_e * (r - sp_at_C - C_c);
                }
            }
        }
        int status = find_max(attack_a,attack_b,attack_c,N);
        if(status == 1){
            H-=attack_a;
            sp_at_A = r;
        }else if(status == 2){
            H-=attack_b;
            sp_at_B = r;
        }else if(status == 3){
            H-=attack_c;
            sp_at_C = r;
        }else{
            H-=N;
        }
        printf("%d ",H);
        if(H <= 0){
            return 0;
        }else{
            if(H+g >= High){
                H = High;
            }else{
                H += g;
            }
        }
    }
}