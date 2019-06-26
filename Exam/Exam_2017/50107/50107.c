#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students{
	char name[64];
	int height;
	int weight;
	double bmi;
}Students;

double countbmi(int h,int w){
	return (w/(h*h));
}

int compare(Students *data1,Students *data2){
	Students *ptr1 = (Students *)data1;
	Students *ptr2 = (Students *)data2;
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
				return strcmp(ptr1->name,ptr2->name);
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	Students students[n];
	for(int i = 0;i<n;i++){
		scanf("%s%d%d",students[i].name,students[i].height,students[i].weight);
		students[i].bmi = countbmi(students[i].height,students[i].weight);
	}
	qsort(students,n,sizeof(Students),compare);
	for(int i = 0;i<n;i++){
		printf("%s %d %d\n",students[i].name,students[i].height,students[i].weight);
	}
}
