/*
 * Author:   段鹏远(alex)
 * Version:  0.1
 * Time:     2014-9-18
 * Function: 输入某年某月某日，判断这一天是这一年的第几天
 */

#include "apue.h"

int is_leap(int year);
int is_year_valid(int year);
int is_month_valid(int month);
int is_date_valid(int year, int month, int day);

int get_year(const char* msg);
int get_month(const char* msg);
int get_day(const char* msg, int year, int month);

//                1   2   3   4   5   6   7   8   9   10  11  12
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char* argv[]){

	int year, month, day;

	year = get_year("Please Input the Year: ");
	month = get_month("the Month: ");
	day = get_day("the Day: ", year, month);

	if( is_leap(year) ){
		months[1] = 29;
	}

	int i, days = 0;
	
	for(i = 0; i < month - 1; i++){
		days += months[i];
	}

	days += day;

	printf("%d.%d.%d is the %d days of this year.\n", year, month, day, days);

	return 0;
}

int is_leap(int year){
	return ( ( (year%4 == 0) && (year%100 != 0) ) || year%400 == 0 );
}

int is_year_valid(int year){
	if(year < 1000 || year > 3000){
		return 0;
	}
	return 1;
}

int is_month_valid(int month){
	if(month < 1 || month > 12){
		return 0;
	}
	return 1;
}


int is_date_valid(int year, int month, int day){
	if(!is_year_valid(year))
		return 0;
	if(!is_month_valid(month))
		return 0;
	if(day < 1 || day > months[month - 1])
		return 0;

	return 1;
}

int get_year(const char* msg){
	int year;

	do{
		printf("%s", msg);
		scanf("%d", &year);
	}while(!is_year_valid(year));

	return year;
}

int get_month(const char* msg){
	int month;

	do{
		printf("%s", msg);
		scanf("%d", &month);
	}while(!is_month_valid(month));

	return month;
}
int get_day(const char* msg, int year, int month){
	int day;

	do{
		printf("%s", msg);
		scanf("%d", &day);
	}while(!is_date_valid(year, month, day));

	return day;
}




