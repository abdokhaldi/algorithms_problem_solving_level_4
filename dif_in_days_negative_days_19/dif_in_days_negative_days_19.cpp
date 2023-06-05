// dif_in_days_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

struct stDate {
    short Day;
    short Month;
    short Year;
};

short ReadMonth() {
    cout << "Enter Month : ";
    short Month;
    cin >> Month;
    return Month;
}

short ReadYear() {
    cout << "Enter Year : ";
    short Year;
    cin >> Year;
    return Year;
}



short ReadDay() {
    cout << "Enter Day : ";
    short Day;
    cin >> Day;
    return Day;
}

stDate ReadFullDate() {
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}


short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month>12)
        return  0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
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



stDate increaseDateByOneDay(stDate Date) {

    if (isLastDayInMonth(Date)) {

        if (isLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year ++ ;
        }
        else {
            Date.Day = 1;
            Date.Month ++;
        }
    }
    else {

        Date.Day++;
    }


    return Date;
}


bool isDate1LessThanDate2(stDate Date1, stDate Date2) {

    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

void SwapDates(stDate &Date1 , stDate &Date2) {
    
    stDate TempDate ;

    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year  = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day   = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {

    short Days = 0;
    short swapFlagValue = 1;

    if(!isDate1LessThanDate2(Date1, Date2) ) {
        SwapDates(Date1,Date2);
        swapFlagValue = -1;
    }

    while (isDate1LessThanDate2(Date1, Date2)) {
        Days++;
        Date1 = increaseDateByOneDay(Date1);
    }

    return (IncludeEndDay) ? ++Days * swapFlagValue : Days * swapFlagValue;
}

int main()
{
    
    stDate Date1 = ReadFullDate();
    cout << endl;
    stDate Date2 = ReadFullDate();


    cout << " the Difference : " << GetDifferenceInDays(Date1, Date2);

    cout << "\n the difference including the last day  : " << GetDifferenceInDays(Date1, Date2, true);



}

