#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "componentPart.h"
/*
typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;
*/

int compare(const void * data1,const void * data2){
	ComponentPart *ptr1 = (ComponentPart *)data1;
	ComponentPart *ptr2 = (ComponentPart *)data2;
	return (strcmp(ptr1->name,ptr2->name));
}

int find(int index, ComponentPart list[]){
	if(list[index].numComponent == 0){
		return list[index].price;
	}else{
		int sum = 0;
		for(int i = 0;i<list[index].numComponent;i++){
			sum += find(list[index].componentPartList[i],list);
		}
		return sum;
	}
}

void findPrice(int N, ComponentPart list[]){
	for(int i = 0;i<N;i++){
		if(list[i].numComponent != 0){
			list[i].price = 0;
			for(int j = 0;j<list[i].numComponent;j++){
				list[i].price += find(list[i].componentPartList[j],list);
			}
		}
	}
	qsort(list,N,sizeof(ComponentPart),compare);
	for(int i = 0;i<N;i++){
		printf("%s %d\n",list[i].name,list[i].price);
	}
}
