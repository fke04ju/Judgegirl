#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[64];
	int height,weight;
	double bmi;
}Student;

double countbmi(int h,int w){
	double h_m = h;
	h_m /= 100;
	return (w/(h_m*h_m));
}

int compare(const void *data1,const void *data2){
	Student *ptr1 = (Student *)data1;
	Student *ptr2 = (Student *)data2;
	if(ptr1->bmi > ptr2->bmi){
		return 1;
	}else if(ptr1->bmi < ptr2->bmi){
		return -1;
	}else{
		if(ptr1->weight > ptr2->weight){
			return 1;
		}else if(ptr1->weight < ptr2->weight){
			return -1;
		}else{
			if(ptr1->height > ptr2->height){
				return 1;
			}else if(ptr1->height < ptr2->height){
				return -1;
			}else{
				return (strcmp(ptr1->name,ptr2->name));
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	Student students[n];
	for(int i = 0;i<n;i++){
		scanf("%s%d%d",students[i].name,&students[i].height,&students[i].weight);
		students[i].bmi = countbmi(students[i].height,students[i].weight);
	}
	qsort(students,n,sizeof(Student),compare);
	for(int i = 0;i<n;i++){
		printf("%s %d %d\n",students[i].name,students[i].height,students[i].weight);
	}
}
