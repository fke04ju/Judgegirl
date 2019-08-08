#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct{
	char name[20];
	int id;
	char phone[10];
	float grade[4];
	int birth_year;
	int birth_month;
	int birth_day;
}Student;

int main(){
	char f1[80],f2[80];
	scanf("%s%s",f1,f2);
	FILE *input;
	FILE *output;
	input = fopen(f1,"rb");
	int num = 0;
	Student count;
	while(fread(&count,sizeof(Student),1,input)){
		num++;
	}
	fclose(input);
	input = fopen(f1,"rb");
	Student table[num];
	fread(table,sizeof(Student),num,input);
	fclose(input);
	output = fopen(f2,"w");
	fputs("<table border=\"1\">\n",output);
	fputs("<tbody>\n",output);
	for(int i = 0;i<num;i++){
		fputs("<tr>\n",output);
		fprintf(output,"<td>%s</td>\n",table[i].name);
		fprintf(output,"<td>%d</td>\n",table[i].id);
		fprintf(output,"<td>%s</td>\n",table[i].phone);
		fprintf(output,"<td>%f, %f, %f, %f</td>\n",table[i].grade[0],table[i].grade[1],table[i].grade[2],table[i].grade[3]);
		fprintf(output,"<td>%d, %d, %d</td>\n",table[i].birth_year,table[i].birth_month,table[i].birth_day);
		fputs("</tr>\n",output);
	}
	fputs("</tbody>\n",output);
	fputs("</table>\n",output);
	fclose(output);
}
