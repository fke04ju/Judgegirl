#include <stdio.h>

struct Class{
    int academic_credit;  
    char score[3];
};
struct Student{
    char name[20];
    int N_class; // total number of classes the student takes.
    int N_credit; // total number of academic credits.
    double GPA;
    struct Class all_class[10];
};
 
void GPA_calculation(struct Student all_student[], int N){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<all_student[i].N_class;j++){
			if(all_student[i].all_class[j].score[0] == 'A'){
				if(all_student[i].all_class[j].score[1] == '+'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*4.3);
				}else if(all_student[i].all_class[j].score[1] == '-'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*3.7);
				}else{
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*4);
				}
			}else if(all_student[i].all_class[j].score[0] == 'B'){
				if(all_student[i].all_class[j].score[1] == '+'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*3.3);
				}else if(all_student[i].all_class[j].score[1] == '-'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*2.7);
				}else{
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*3.0);
				}
			}else if(all_student[i].all_class[j].score[0] == 'C'){
				if(all_student[i].all_class[j].score[1] == '+'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*2.3);
				}else if(all_student[i].all_class[j].score[1] == '-'){
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*1.7);
				}else{
					all_student[i].GPA += (all_student[i].all_class[j].academic_credit*2.0);
				}
			}else{
				all_student[i].GPA += 0;
			}
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
		}
		all_student[i].GPA /= all_student[i].N_credit;
	}
	for(int i = 0;i<N-1;i++){
		for(int j = 0;j<N-i-1;j++){
			if(all_student[j].GPA < all_student[j+1].GPA){
				struct Student tmp;
				tmp = all_student[j];
				all_student[j] = all_student[j+1];
				all_student[j+1] = tmp;
			}
		}
	}
	int award_num = ((N-1)/20)+1;
	int award_count = 1;
	for(int i = 0;i<N && award_count <= award_num;i++){
		if(all_student[i].GPA >= 3.38 && all_student[i].N_credit >= 15){
			printf("%d %s %f\n",award_count,all_student[i].name,all_student[i].GPA);
		}
		award_count++;
	}
}
