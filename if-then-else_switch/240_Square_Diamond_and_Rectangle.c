#include <stdio.h>
int main(){
    int n,a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H,i;
    int ac,ae,ag,bd,bf,bh,ce,cg,df,dh,eg,fh;
    scanf("%d",&n);
    for(i=0;i<n;i++){  //逆時針
        scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
        ac = c-a;
		ae = e-a;
		ag = g-a;
        bd = d-b;
		bf = f-b;
		bh = h-b;
        ce = e-c;
		cg = g-c;
		df = f-d;
		dh = h-d;
		eg = g-e;
		fh = h-f;
        if(ac*bf - bd*ae > 0 && ac*bh - ag*bd > 0){
            if(ae*bh - ag*bf > 0){
                A=a;
				B=b;
				C=c;
				D=d;
				E=e;
				F=f;
				G=g;
				H=h;
            }else{
                A=a;
				B=b;
				C=c;
				D=d;
				E=g;
				F=h;
				G=e;
				H=f;
            }
        }else if(ac*bf - ae*bd < 0 && ac*bh - bd*ag > 0){
            A=a;
			B=b;
			C=e;
			D=f;
			E=c;
			F=d;
			G=g;
			H=h;
        }else if(ac*bf - ae*bd > 0 && ac*bh - bd*ag < 0){
            A=a;
			B=b;
			C=g;
			D=h;
			E=c;
			F=d;
			G=e;
			H=f;
        }else if(ac*bf - bd*ae < 0 && ac*bh - ag*bd < 0){
            if(ag*bf - ae*bh < 0){
                A=a;
				B=b;
				C=e;
				D=f;
				E=g;
				F=h;
				G=c;
				H=d;
            }else{
                A=a;
				B=b;
				C=g;
				D=h;
				E=e;
				F=f;
				G=c;
				H=d;
            }
        }
        //printf("%d%d%d%d%d%d%d%d",A,B,C,D,E,F,G,H);
        if((C-A)*(C-A) + (D-B)*(D-B) == (C-E)*(C-E) + (D-F)*(D-F) && ((C-E)*(C-E) + (D-F)*(D-F) == (G-E)*(G-E) + (H-F)*(H-F) && (G-E)*(G-E) + (H-F)*(H-F) == (A-G)*(A-G) + (B-H)*(B-H))){
            if((C-A)*(C-E) + (D-B)*(D-F) == 0){
                printf("square\n");
            }else{
                printf("diamond\n");
            }
        }else if((C-A)*(C-E) + (D-B)*(D-F) == 0 && ((E-C)*(E-G) + (F-D)*(F-H) == 0) && ((G-E)*(G-A) + (H-F)*(H-B) == 0) && ((A-G)*(A-C) + (B-H)*(B-D) == 0)){
            printf("rectangle\n");
        }else{
			printf("other\n");
		}
    }
}
