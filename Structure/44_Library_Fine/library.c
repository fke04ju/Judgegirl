#include "book.h"
#include "date.h"
int days_of_month(int y,int m){
    if(m == 2){
        if(y%4 == 0 && y%100 != 0 || y%400 == 0){
            return 29;
        }else{
            return 28;
        }
    }else{
        if(m == 4 || m == 6 || m == 9 || m == 11){
            return 30;
        }else{
            return 31;
        }
    }
}
 
int days_before(struct Date date_any){
    int result = 0;
    for(int i = 1;i<=12;i++){
        if(i == date_any.month){
            result += date_any.day;
            return result;
        }else{
            result += days_of_month(date_any.year,i);
        }
    }
}
 
int days_of_year(int y){
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        return 366;
    }else{
        return 365;
    }
}
 
int cal_day(struct Date date_borrowed,struct Date date_returned){
    int result = 0;
    for(int i = date_borrowed.year;i<date_returned.year;i++){
        result += days_of_year(i);
    }
    result = result - days_before(date_borrowed) + days_before(date_returned)+1;
    //printf ("result=%d\n", result);
    return result;
}
 
unsigned int cal_fine(int n,unsigned int important){
    int day_fine = 0;
    while(important%2!=1){
        important>>=1;
    }
    important>>=1;
    while(important%2 != 1){
        important /=2;
        day_fine++;
    }
    return n*day_fine;
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
    int borrow_day = cal_day(date_borrowed,date_returned);
    if(book.type == 0){//NOVEL
        if(borrow_day > 90){
            return cal_fine(borrow_day-90,book.importance);
        }else{
            return 0;
        }
    }else if(book.type == 1){//COMICS
        if(borrow_day > 10){
            return cal_fine(borrow_day-10,book.importance);
        }else{
            return 0;
        }
    }else if(book.type == 2){//MANUAL
        if(borrow_day > 100){
            return cal_fine(borrow_day-100,book.importance);
        }else{
            return 0;
        }
    }else{//TEXTBOOK
        if(borrow_day > 5){
            return cal_fine(borrow_day-5,book.importance);
        }else{
            return 0;
        }
    }
}