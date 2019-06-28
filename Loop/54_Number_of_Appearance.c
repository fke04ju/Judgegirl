nclude <stdio.h>
int main(){
	    int m,n;
		int sum=0;
		scanf("%d",&n);
		scanf("%d",&m);
		if(m%100==n) sum++;
		if(((m%1000)-m%10)/10==n) sum++;
		if(((m%10000)-m%100)/100==n) sum++;
	    if(((m%100000)-m%1000)/1000==n) sum++;
	    if(((m%1000000)-m%10000)/10000==n) sum++;
		if(m/100000==n) sum++;
		printf("%d",sum);
	}
}
