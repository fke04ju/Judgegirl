#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
	Employee *e1 = (Employee *)malloc(sizeof(Employee));
	strcpy(e1->first_name,employee1->first_name);
	strcpy(e1->first_name,employee1->last_name);
	e1->boss = employee1->boss;
	Employee *e2 = (Employee *)malloc(sizeof(Employee));
	strcpy(e2->first_name,employee2->first_name);
	strcpy(e2->first_name,employee2->last_name);
	e2->boss = employee2->boss;

	Employee *tmp1 = e1;
	while(tmp1 != tmp1->boss){
		if(tmp1->boss == employee2){
			return 1;
		}
		tmp1 = tmp1->boss;
	}
	Employee *tmp2 = e2;
	while(tmp2 != tmp2->boss){
		if(tmp2->boss == employee1){
			return 2;
		}
		tmp2 = tmp2->boss;
	}

	Employee *root1 = employee1;
	Employee *root2 = employee2;
	while(root1->boss != root1){
		root1 = root1->boss;
	}
	while(root2->boss != root2){
		root2 = root2->boss;
	}
	if(!strcmp(root1->first_name,root2->first_name) && !strcmp(root1->last_name,root2->last_name)){
		return 3;
	}else{
		return 4;
	}
}
