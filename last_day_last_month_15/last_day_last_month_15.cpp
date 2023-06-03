// last_day_last_month_15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

short ReadDay() {
    cout << "please enter day : ";
    short Day;
    cin >>  Day;
    return Day;
}

short ReadMonth() {
    cout << "please enter Month : ";
    short Month;
    cin >> Month;
    return Month;
}

short ReadYear() {
    cout << "please enter Year : ";
    short Year;
    cin >> Year;
    return Year;
}


struct stDate {
    short Day;
    short Month;
    short Year;
};

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month , short Year) {

    if (Month < 1 || Month>12) 
        return  0;

   int Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   return (Month == 2 ) ? (isLeapYear(Year) ? 29 : 28)  : Days[Month -1];
}



stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
        return Date;
}



bool isLastDayInMonth(stDate Date) {

    short LastDay = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day == LastDay)
        return true;
    else
        return false;
}

bool isLastMonthInYear(short Month) {
    return (Month == 12);
}

int main()
{
    stDate Date;
    Date = ReadFullDate();

    if (isLastDayInMonth(Date) ) {
        cout << " \n yes , it is last day in month ";
    }
    else {
        cout <<  "\n No , it is not last day in month ";
    }

    if (isLastMonthInYear(Date.Month)) {
        cout << " \n yes , it is last Month in a year ";
    }
    else {
        cout << " \n No , it is Not last Month in a year ";
    }
}
