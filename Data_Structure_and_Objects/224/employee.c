#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
void init_storage(Employee **storage, int n){
	// allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
void free_storage(Employee **storage){
	free(*storage);
    *storage = 0;
}
Employee* find_employee_by_id( Employee *set, int n, int id ){
	Employee *new = (Employee *)malloc(sizeof(Employee));
	for(int i = 0;i<n;i++){
		if(set[i].id == id){
			new->id = id;
			strcpy(new->first_name,set[i].first_name);
			strcpy(new->last_name,set[i].last_name);
			new->boss_id = set[i].boss_id;
			break;
		}
	}
	return new;
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
	Employee *new = (Employee *)malloc(sizeof(Employee));
	for(int i = 0;i<n;i++){
		if(!strcmp(first_name,set[i].first_name) && !strcmp(last_name,set[i].last_name)){
			new->id = set[i].id;
			strcpy(new->first_name,first_name);
			strcpy(new->last_name,last_name);
			new->boss_id = set[i].boss_id;
			break;
		}
	}
	return new;
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
	Employee *tmp = (Employee *)malloc(sizeof(Employee));
	tmp->id = employee->id;
	tmp->boss_id = employee->boss_id;
	int now_id = 0;
	while(tmp->boss_id != tmp->id){
		for(int i = 0;i<n;i++){
			if(set[i].id == tmp->boss_id){
				now_id = i;
				tmp->id = set[i].id;
				tmp->boss_id = set[i].boss_id;
				break;
			}
		}
	}
	strcpy(tmp->first_name,set[now_id].first_name);
	strcpy(tmp->last_name,set[now_id].last_name);
	return tmp;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
	Employee *curr = (Employee *)malloc(sizeof(Employee));
	curr->id = A->id;
	curr->boss_id = A->boss_id;
	while(curr->boss_id != curr->id){
		if(curr->boss_id == B->id){
			return 1;
		}
		for(int i = 0;i<n;i++){
			if(curr->boss_id == set[i].id){
				curr->id = set[i].id;
				curr->boss_id = set[i].boss_id;
				break;
			}
		}
	}
	curr->id = B->id;
	curr->boss_id = B->boss_id;
	while(curr->boss_id != curr->id){
		if(curr->boss_id == A->id){
			return 2;
		}
		for(int i = 0;i<n;i++){
			if(curr->boss_id == set[i].id){
				curr->id = set[i].id;
				curr->boss_id = set[i].boss_id;
				break;
			}
		}
	}
	Employee *A_root = find_root_boss(set,n,A);
	Employee *B_root = find_root_boss(set,n,B);
	if(A_root->id == B_root->id){
		return 3;
	}else{
		return -1;
	}
}

