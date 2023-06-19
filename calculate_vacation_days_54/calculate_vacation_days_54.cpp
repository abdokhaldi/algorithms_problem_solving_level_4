// calculate_vacation_days_54.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


struct stDate {
    short Day;
    short Month;
    short Year;
};


short ReadYear() {
    short Year;
    cout << "Enter Year : ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month;
    cout << "enter Month : ";
    cin >> Month;
    return Month;
}

short ReadDay() {
    short Day;
    cout << "Enter Day : ";
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


short DayOfWeakOrder(short Day, short Month, short Year) {
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // Gregorian://0:sun, 1:Mon, 2:Tue...etc

    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

short DayOfWeakOrder(stDate Date) {
    return DayOfWeakOrder(Date.Day, Date.Month, Date.Year);
}

string  DayShortName(short Day) {

    string arrWeekDays[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday" };
    return arrWeekDays[Day];
}

bool IsWeakEnd(stDate Date) {
    short DayIndex = DayOfWeakOrder(Date.Day, Date.Month, Date.Year);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBussinessDay(stDate Date) {

    return !IsWeakEnd(Date);
}

bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {
    short Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool IsLastDayInMonth(stDate Date) {
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return Date;
}

bool IsDate1BeforDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short GetDiferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforDate2(Date1, Date2)) {
        if(IsBussinessDay(Date1))
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days-1 : Days-1;
}

short VacationDaysNumber(stDate Date1,stDate Date2) {

     return   GetDiferenceInDays(Date1, Date2, true);
    
}

int main()
{
    stDate Date1 = ReadFullDate();
    cout << "\n";
    stDate Date2 = ReadFullDate();

    cout << "\n  Vacation From : " << DayShortName(DayOfWeakOrder(Date1)) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    cout << "\n  Vacation To : " << DayShortName(DayOfWeakOrder(Date2)) << " , " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year;

    cout << "\n \n Actucal Vacation Days is : " << VacationDaysNumber(Date1, Date2);
}

