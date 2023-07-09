#include <stdio.h>

int isLeapYear(int y){
    if(y%400 == 0 || (y%100!=0 && y%4 == 0)){
        return 1;  
    }
    return 0;
}

int main(){
    int m,y;
    printf("Enter year: ");
    scanf("%d",&y);
    printf("Enter month: ");
    scanf("%d",&m);

    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("====================\n");
    printf("%s %d\n",month[m-1], y);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int skip = 1;
    int curyear = 1990;
    while(curyear < y){
        if(isLeapYear(curyear) == 1){
            skip += 1;
        }
        skip+=365;
        curyear++;
    }
    if(m>2 && isLeapYear(y) == 1) skip++;
    for(int i=0;i<m-1;i++){
        skip+=monthday[i];
    }
    skip%=7;
    int day = 1;
    int dayinweek = 0;
    
    while(day<=monthday[m-1]){
        if (skip>0){
            printf("    ");
            skip--;
            dayinweek++;
            continue;
        }
        printf("%3d ", day);
        dayinweek++;
        day++;
        if (dayinweek == 7){
            printf("\n");
            dayinweek = 0;
        } 
    }
    
    return 0;
}