#include <stdio.h>
#define MAXN 500
#define MAX 2147483647

int main(){
    int machine_time[MAXN] = {};
    int jobs[MAXN][MAXN][2] = {};
    int jobs_num[MAXN] = {};
    int next_position[MAXN] = {};
    int completion_time[MAXN] = {};
    int n,m;
    int total_jobs = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d%d",&completion_time[i],&jobs_num[i]);
        for(int j = 0;j<jobs_num[i];j++){
            scanf("%d%d",&jobs[i][j][0],&jobs[i][j][1]);
            total_jobs++;
        }
    }
    while(total_jobs != 0){
        int min_time = MAX;
        int job_index = 0,machine_index = 0;
        for(int i = 0;i<m;i++){
            int next_pos = next_position[i];
            int machine_id = jobs[i][next_pos][0];
            int early_start,cptime;
            if(next_pos == jobs_num[i]){
                continue;
            }
            if(machine_time[machine_id] < completion_time[i]){
                early_start = completion_time[i];
            }else{
                early_start = machine_time[machine_id];
            }
            cptime = early_start+jobs[i][next_pos][1];
            if(cptime < min_time){
                min_time = cptime;
                job_index = i;
                machine_index = machine_id;
            }
        }
        next_position[job_index]++;
        completion_time[job_index] = min_time;
        machine_time[machine_index] = min_time;
        total_jobs--;
    }
    for(int i = 0;i<m;i++){
        printf("%d\n",completion_time[i]);
    }
}