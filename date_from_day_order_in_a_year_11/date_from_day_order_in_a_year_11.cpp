// days_from_begining_of_year_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;


bool checkTypeYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month > 12) {
        return 0;
    }

    short arr31Days[12] = { 31,28,31,30, 31,30, 31,31, 30,31, 30,31 };

    return Month == 2 ? (checkTypeYear(Year) ? 29 : 28) : (arr31Days[Month - 1]);
}

short ReadDay() {
    short Day;
    cout << "please enter a day : ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "please enter a Month : ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "please enter a Year : ";
    cin >> Year;
    return Year;
}

short NumberOfDaysFromTheBeginingOfTheAyear(short Day, short Month, short Year) {

    short TotalDays = 0;
    for (short i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInMonth(i, Year);
    }
    TotalDays += Day;

    return TotalDays;
}

struct sDate {
    short Year;
    short Month;
    short Day;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
    sDate Date;
    short RemainingDays = DateOrderInYear;
   short  MonthDays = 0;
   Date.Year = Year;
   Date.Month = 1;
    while (true) {
        MonthDays = NumberOfDaysInMonth(Date.Month , Year);
        if (MonthDays < RemainingDays) {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;

}



int main()
{
   
    
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short OrderDaysInYear = NumberOfDaysFromTheBeginingOfTheAyear(Day, Month, Year);

   sDate Date;
    Date = GetDateFromDayOrderInYear(OrderDaysInYear,Year);

    cout << "the number of days in a year " << Year << " is : " << OrderDaysInYear << "\n";

    cout << "Date is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

    system("pause>0");
    return 0;

}

