// your_age_in_days_18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <ctime>

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
    cout << " Please Enter Birthday : \n\n";
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

stDate GetSystemDate() {
    stDate Date; 

    time_t t = time(0);
    tm localtime;
    localtime_s(&localtime, &t);

    Date.Year  = localtime.tm_year + 1900;
    Date.Month = localtime.tm_mon + 1;
    Date.Day = localtime.tm_mday;

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


bool isDate1LessThanDate2(stDate Date1, stDate Date2) {

    
    
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}


short GetYourAgeInDays(stDate Date1, stDate Date2) {

    short Days = 0;
    while (isDate1LessThanDate2(Date1, Date2)) {
        Days++;
        Date1 = increaseDateByOneDay(Date1);
    }
    return  Days;
}






int main()
{

    stDate Birthday = ReadFullDate();

    stDate RecentDate = GetSystemDate();
    

    cout << "\nYour Age In Days Is : " << GetYourAgeInDays(Birthday , RecentDate);

   



}
