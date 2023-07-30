#include <stdio.h>
typedef struct datetime {
    int date; // 1-31
    int month; // 1-12
    int year; // 1970++
    int dayOfWeek; // 0-6
    int hour; // 0-23
    int minute; // 0-59
    int second; // 0-59
} datetime_t;

int isLeapYear(int n){
    if(n%4==0 && (n%100!=0 || n%400==0)){
        return 1;
    }
    return 0;
}
datetime_t createDate(int n) {
    datetime_t today = {1,0,1970,4,0,0,0};
    int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    today.second = n%60;
    today.minute = (n%3600)/60;
    today.hour = (n/3600)%24;
    int day = (n/3600)/24;
    today.dayOfWeek = (today.dayOfWeek+day)%7;
    while(day >= 366){
        if(isLeapYear(today.year)){
            day--;
        }
        day-=365;
        today.year++;
    }
    if(isLeapYear(today.year)){
        monthday[1]++;
    }
    for(int i=0;i<12;i++){
        if(day >= monthday[i]){
            day-=monthday[i];
            today.month++;
        }
        else{
            break;
        }
    }
    today.date+=day;
    return today;
}
void printDate(datetime_t t) {
    char dayofweek[7][10] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char month[12][10] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

    printf("%s %d %s %d %02d:%02d:%02d",
    dayofweek[t.dayOfWeek], t.date, month[t.month],
    t.year, t.hour, t.minute, t.second);
}
int main(void) {
    datetime_t inputDate;
    int timestamp;

    scanf("%d", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}