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

short ReadHowManyDaysToAdd() {
    short Days;
    cout << "How Many Days To Add : ";
    cin >> Days;
    return Days;
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

short NumberOfDaysFromTheBeginingOfTheAyear(short Day, short Month, short Year ) {

    short TotalDays = 0;
    for (short i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInMonth(i, Year);
    }
    TotalDays += Day;

    return TotalDays  ;
}

struct sDate {
    short Year;
    short Month;
    short Day;
};

sDate DateAddDays(short   Days, sDate Date) {
   
   int RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheAyear(Date.Day, Date.Month, Date.Year) ;
    short  MonthDays = 0;
    
    Date.Month = 1;
    while (true) {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (MonthDays < RemainingDays) {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;

}

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}



int main()
{


   sDate Date  = ReadFullDate();
   int Days = ReadHowManyDaysToAdd();
    

    
    Date = DateAddDays(Days , Date);

    cout << " Date after adding [" << Days << "] is :    ";
    cout <<  Date.Day << " / " << Date.Month << " / " << Date.Year << "\n";

   
    system("pause>0");
    return 0;

}

