#include<stdio.h>

int main(){
    int dayLimit[2][13] = {{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
    int day, month, year;
    int tmp, x; // ddmmyyyy
    printf("Date (ddmmyyyy): ");
    scanf("%d", &tmp);
    printf("X: ");
    scanf("%d", &x);
    year = tmp%10000;
    month = tmp/10000%100;
    day = tmp/1000000+x;
    while(day>dayLimit[year%4==0?0:1][month]){
        day -= dayLimit[year%4==0?0:1][month];
        month++;
        if(month == 13){
            month  = 1;
            year++;
        }
    }
    printf("Result: %d/%d/%d", day,month,year);
}