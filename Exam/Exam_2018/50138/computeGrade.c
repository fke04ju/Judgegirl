#include <stdio.h>

typedef struct{
    int rawScore;
    double scaledScore;
}Score;
 
typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;
 
typedef struct{
    int numStudent;
    Student student[1000];
}Classes;

void computeGrade(Classes classes[2]){
	double average_score_0[18] = {};
	double average_score_1[18] = {};
	double ratio;
//	calculate average score
	for(int i = 0;i<18;i++){
		for(int j = 0;j<classes[0].numStudent;j++){
			average_score_0[i] += classes[0].student[j].score[i].rawScore;
		}
		average_score_0[i] /= classes[0].numStudent;
//		printf("classes[0].%d: average score is %f\n",i,average_score_0[i]);
	}
	for(int i = 0;i<18;i++){
		for(int j = 0;j<classes[1].numStudent;j++){
			average_score_1[i] += classes[1].student[j].score[i].rawScore;
		}
		average_score_1[i] /= classes[1].numStudent;
//		printf("classes[1].%d: average score is %f\n",i,average_score_1[i]);
	}
//	calculate scaled score
	for(int i = 0;i<18;i++){
		if(average_score_0[i] > average_score_1[i]){
			ratio = (average_score_0[i] / average_score_1[i]);
			for(int j = 0;j<classes[1].numStudent;j++){
				classes[1].student[j].score[i].scaledScore = ratio * classes[1].student[j].score[i].rawScore;
				if(classes[1].student[j].score[i].scaledScore > 100){
					classes[1].student[j].score[i].scaledScore = 100;
				}
			}
			for(int j = 0;j<classes[0].numStudent;j++){
				classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore;
			}
		}else{
			ratio = (average_score_1[i] / average_score_0[i]);
			for(int j = 0;j<classes[0].numStudent;j++){
				classes[0].student[j].score[i].scaledScore = ratio * classes[0].student[j].score[i].rawScore;
				if(classes[0].student[j].score[i].scaledScore > 100){
					classes[0].student[j].score[i].scaledScore = 100;
				}
			}
			for(int j = 0;j<classes[1].numStudent;j++){
				classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore;
			}
		}
//		printf("exam %d's ratio = %f\n",i,ratio);
	}
/*
	for(int i = 0;i<2;i++){
		for(int j = 0;j<classes[i].numStudent;j++){
			for(int k = 0;k<18;k++){
				printf("class[%d]'s student %d's exam %d's scaled score is %f\n",i,j,k,classes[i].student[j].score[k].scaledScore);
			}
		}
	}
*/
//	calculate final score
	for(int i = 0;i<2;i++){
		for(int j = 0;j<classes[i].numStudent;j++){
			double sum = 0;
			for(int k = 0;k<18;k++){
				sum += classes[i].student[j].score[k].scaledScore;
			}
			sum *= 0.06;
			if(sum > 100){
				sum = 100;
			}
			classes[i].student[j].finalScore = sum;
		}
	}
	for(int i = 0;i<2;i++){
		for(int j = 0;j<classes[i].numStudent;j++){
			printf("%s %f\n",classes[i].student[j].id,classes[i].student[j].finalScore);
		}
	}
}
