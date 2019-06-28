nclude <stdio.h>
int main(){
	    int year,first_day_name,n,month,day,i;
	    scanf("%d%d\n%d",&year,&first_day_name,&n);
	    for(i=0;i<n;i++){
        int sum=0;
		scanf("%d%d",&month,&day);
		if(month>12 ||month<1) printf("-1\n");
		else if(year%4==0&&year%100!=0||year%400==0){
		if(month==1){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=-1+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==3){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=59+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==2){
			if(day>29|| day<1){
				printf("-2\n");
			}else{
				sum=30+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==4){
			if(day>30|| day<1){
				printf("-2\n");
			}else{
				sum=90+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==5){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=120+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==6){
			if(day>30|| day<1){
				printf("-2\n");
			}else{
				sum=151+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==7){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=181+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==8){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=212+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==9){
			if(day>30|| day<1){
				printf("-2\n");
			}else{
				sum=243+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==10){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=273+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==11){
			if(day>30|| day<1){
				printf("-2\n");
			}else{
				sum=304+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}else if(month==12){
			if(day>31|| day<1){
				printf("-2\n");
			}else{
				sum=334+day+first_day_name;
				printf("%d\n",sum%7);
			}
		}
		}else{
			if(month==1){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=-1+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==3){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=58+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==2){
				if(day>28|| day<1){
					\printf("-2\n");
				}else{
					sum=30+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==4){
				if(day>30|| day<1){
					printf("-2\n");
				}else{
					sum=89+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==5){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=119+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==6){
				if(day>30|| day<1){
					printf("-2\n");
				}else{
					sum=150+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==7){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=180+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==8){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=211+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==9){
				if(day>30|| day<1){
					printf("-2\n");
				}else{
					sum=242+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==10){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=272+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==11){
				if(day>30|| day<1){
					printf("-2\n");
				}else{
					sum=303+day+first_day_name;
					printf("%d\n",sum%7);
				}
			}else if(month==12){
				if(day>31|| day<1){
					printf("-2\n");
				}else{
					sum=333+day+first_day_name;
					printf("%d\n",sum%7);
				}
	`		}
		}
	}
}
													}
													}
													}
													}
													}
													}
													}
													}
													}
													}
													}
													}
											}
															}
															}
															}
															}
															}
															}
															}
															}
															}
															}
															}
															}
													}
				}
}
