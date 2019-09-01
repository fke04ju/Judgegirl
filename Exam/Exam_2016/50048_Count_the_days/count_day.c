void count_day(int year, int day, int month, int results[7]){
    int not_run[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int run[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int if_run;
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
        if_run = 1;
    }else{
        if_run = 0;
    }
    int first_of_month = day;
    for(int i = 1;i<month;i++){
        first_of_month+=((if_run == 1)?run[i]:not_run[i]);
    }
    first_of_month %= 7;
    if(if_run == 1){
        int count = 0;
        for(int i = first_of_month;i<7;i++){
            results[i]++;
            count++;
        }
        while(count < run[month]){
            for(int i = 0;i<7 && count < run[month];i++){
                count++;
                results[i]++;
            }
        }
    }else{
        int count = 0;
        for(int i = first_of_month;i<7;i++){
            results[i]++;
            count++;
        }
        while(count < not_run[month]){
            for(int i = 0;i<7 && count < not_run[month];i++){
                count++;
                results[i]++;
            }
        }
    }
    return;
}